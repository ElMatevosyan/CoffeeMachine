#ifndef __COFFEE__
#define __COFFEE__
#include <string>

struct Transaction
{
   	std::string sOrder;
       	float nMoney;
        Transaction(); //դատարկն ինչի համար է։
        Transaction(const std::string& sMyOrder, float nMyMoney);
};

class CoffeeMachine
{
private:
        int m_nSize;
        std::string* m_arrTypes;
        float* m_arrPrice;
public:
        CoffeeMachine();
        CoffeeMachine(std::string* arrTypes, float* arrPrice, int Size);
        CoffeeMachine(const CoffeeMachine& other);
        ~CoffeeMachine();
        void printPriceList();
        Transaction change(const Transaction& order);
};

#endif //__COFFEE__
