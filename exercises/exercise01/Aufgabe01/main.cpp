#include <iostream>
#include <string>

int main()
{
    std::string name;

    std::cout << "What is your given name?\n";
    std::cin>>name;
    
    for(int count = 0; count <10; ++count)
      std::cout<< "Hello " << name<<std::endl;
     return 0;
     
   }
   

