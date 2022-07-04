#include "sieve.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>

Sieve::Sieve(std::vector<std::size_t>& numbers) : numbers(numbers) {} //inistralliert privatemember std::vector<std::size_t> numbers;
//numbers
void Sieve::reduceToPrimes()
{
    // TODO: Implement reduceToPrimes
     std::sort(this->numbers.begin(),this->numbers.end()); //member,ein privatemember in Konstruktor, kann heir dierekt bebutzen? this->?
    std::size_t n;
    auto prev=[&n](std::size_t v_number){v_number!=n && v_number%n==0;};
    for (n=2;n!=(std::size_t)(sqrt(numbers.size()));++n)
     numbers.erase(std::remove_if(numbers.begin(),numbers.end(),prev),numbers.end());
     
}

void Sieve::resetToSize(std::size_t size)
{
    // TODO: Implement resetToSize    
}

void Sieve::groupNumbers(std::size_t lowerBound, std::size_t upperBound)
{
    // TODO: Implement groupNumbers
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



