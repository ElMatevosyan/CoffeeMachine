#include "CoffeeMachine.h"
#include "test.h"
#include <iostream>

int main()
{
	std::cout << "By default the coffee machine offers: " << std::endl;	
	CoffeeMachine CM;
	CoffeeMachine CMcopy(CM);
	CMcopy.printPriceList();
	std::cout<<std::endl;
	
	test();
}	
