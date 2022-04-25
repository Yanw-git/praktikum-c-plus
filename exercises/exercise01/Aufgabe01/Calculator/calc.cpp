#include <string>
#include <iostream>

int main()
{
    int numberA;
    int numberB;
    std::string operation;    

    // TODO: Add code here
       int Ergebnis;
		
		std::cout << "numberA=";
		std::cin >> numberA;
		std::cout << "numberB=";
		std::cin >>numberB;
		std::cout << "operation:";
		std::cin >> operation;
		if (operation == "add")
	{
		Ergebnis = numberA + numberB;
		std::cout << Ergebnis << std::endl;
	}

	if (operation == "sub")
	{
		Ergebnis = numberA - numberB;
		std::cout << Ergebnis << std::endl;
	}

	if (operation != "add" && operation != "sub")
		std::cout << "Falsch" << std::endl;
       
    return 0;
}


