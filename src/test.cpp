#include "test.h"
#include "CoffeeMachine.h"
#include <iostream>

void test()
{
std::cout << "Test N1- new drink list:" << std::endl;
	int Size = 5;
	std::string* arrProduct = new std::string[Size] { "Espresso", "Americano", "Cappuccino", "Latte", "Mocha" };
    	float* arrPrice = new float[Size] { 2, 2, 1.5, 3, 2.25 };

	CoffeeMachine newList( arrProduct, arrPrice, Size );	
	newList.printPriceList();

	std::cout<<std::endl;
	
	CoffeeMachine cm;
std::cout << "Test N2- case: return change." << std::endl;
	Transaction myOrder1( "Cappuccino", 10 );
	Transaction readyOrder1 = cm.change( myOrder1 );
	std::cout << readyOrder1.sOrder << " $" << readyOrder1.nMoney << std::endl;

std::cout << "Test N3- case: not enough money." << std::endl;
	Transaction myOrder2("Cappuccino", 1 );
	Transaction readyOrder2 = cm.change( myOrder2 );
	std::cout << readyOrder2.sOrder << " $" << readyOrder2.nMoney << std::endl;

std::cout << "Test N3- case: no this coffee." << std::endl;
	Transaction myOrder3("Cola", 10);
	Transaction readyOrder3 = cm.change( myOrder3 );
	std::cout << readyOrder3.sOrder << " $" << readyOrder3.nMoney << std::endl;
}
