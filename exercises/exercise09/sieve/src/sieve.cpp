#include "sieve.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>

Sieve::Sieve(std::vector<std::size_t>& numbers) : numbers(numbers) {} //inistralliert privatemember of SIeve std::vector<std::size_t> numbers;
// Sieve::Sieve( std::vector<std::size_t>& numbers):numbers(numbers) {}
void Sieve::reduceToPrimes()
{
    // TODO: Implement reduceToPrimes
     std::sort(this->numbers.begin(),this->numbers.end());        //Achtung!std::sort(SIEVE.numbers.begin(),this->numbers.end()); bumeng yong yige jutide shilihua duixiang qu sheji yigelei,yinwei zhegelei haizai goujian zhong.obly use this to instead of the obj
    //auto pred=[&n](std::size_t v_number){v_number!=n && v_number%n==0;};
    for (std::size_t n=2;n!=100;++n)
    { auto pred=[&n](std::size_t number){return number%n==0 && number!=n;};
     numbers.erase(std::remove_if(numbers.begin(),numbers.end(),pred),numbers.end());
    }   
}

void Sieve::resetToSize(std::size_t size)
{
    // TODO: Implement resetToSize    
    /*auto pred=[&size,&numbers](std::size_t number){
        for(auto & i:numbers) */   //WRONG: number in KlammerBedeutet JEDE Element of numbers, no need to Durchlafen von vector!
    /* auto pred=[&size](std::size_t number){   
         return number>size; 
    };*/
    
this->numbers.erase(std::remove_if(numbers.begin(),numbers.end(),[&size](std::size_t number){ return number>size;}),numbers.end());
     for(size_t i=2;i>size;++i)   //2-Grosse
    {
     auto pred=[&i](std::size_t number){ return number!=i;};   
     std::find_if(numbers.begin(),numbers.end(),pred);
      //auto pred=[&i](std::size_t number){ number!=i;};   
     numbers.push_back(i);
    }
    std::sort(numbers.begin(),numbers.end(),[](std::size_t number1,std::size_t number2){ return number1>number2;});
}

void Sieve::groupNumbers(std::size_t lowerBound, std::size_t upperBound)
{
    // TODO: Implement groupNumbers
std::stable_partition(numbers.begin(),numbers.end(),[lowerBound,upperBound ](std::size_t number){return number>lowerBound && number<upperBound;});
std::sort(numbers.begin(),numbers.end());
}

void Sieve::printNumbers(std::ostream& os)
{
    os << "{";
    for (std::size_t i = 0; i < this->numbers.size() - 1; ++i)
    {
        os << this->numbers[i] << ", ";
    }
    os << this->numbers[this->numbers.size() - 1] << "}\n\n" << std::flush;
}



