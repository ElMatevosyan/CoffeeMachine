#include "CoffeeMachine.h"
#include <iostream>

Transaction::Transaction()
    : sOrder("")
    , nMoney(0)
{
}

Transaction::Transaction(const std::string& sMyOrder, float nMyMoney)
    : sOrder(sMyOrder)
    , nMoney(nMyMoney)
        {
        }

CoffeeMachine::CoffeeMachine()
    : m_nSize(3)
    , m_arrTypes (new std::string[3] {"Americano", "Cappuccino", "Latte"})
    , m_arrPrice(new float[3] {2, 1.5, 3})
{
}

CoffeeMachine::CoffeeMachine(std::string* arrTypes, float* arrPrice, int nSize)
    : m_nSize(nSize)
    , m_arrTypes(arrTypes)
    , m_arrPrice(arrPrice)
{
}

CoffeeMachine::CoffeeMachine(const CoffeeMachine& other)
{
    m_nSize = other.m_nSize;
    m_arrTypes = new std::string[other.m_nSize];
    m_arrPrice = new float[other.m_nSize];
    for(int i=0; i<other.m_nSize; i++)
    {
        m_arrTypes[i] = other.m_arrTypes[i];
        m_arrPrice[i] = other.m_arrPrice[i];
    }
    

}

CoffeeMachine::~CoffeeMachine()
{
        delete[] m_arrTypes;
        m_arrTypes = nullptr;
        delete[] m_arrPrice;
        m_arrPrice = nullptr;
}

void CoffeeMachine::printPriceList()
{
        for(int i=0; i<m_nSize; i++)
        std::cout << "\t" <<  m_arrTypes[i] << " costs $" << m_arrPrice[i] << std::endl;
}

Transaction CoffeeMachine::change(const Transaction& order) 
{
        //պահված է nMoney ու sOrder ֊ը
        Transaction result ("Sorry, we don't have that kind of coffee", order.nMoney);
        for( int i=0; i<m_nSize; i++)
        {
                if(order.sOrder != m_arrTypes[i])
                continue;

                else
                {
                    if(order.nMoney >= m_arrPrice[i])
                    {
                    result.sOrder = m_arrTypes[i];
                    result.nMoney = order.nMoney - m_arrPrice[i];
                    return result;
                    }

                    else
                    {
                    result.sOrder = "Sorry, not enough money!";
                    return result;
                    }
                }
	}
        return result;
}
