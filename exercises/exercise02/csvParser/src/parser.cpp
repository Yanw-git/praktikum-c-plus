/**
 * @file parser.cpp
 */
#include "parser.h"
#include <sstream>

std::vector<std::string> split(std::itream& is, char delim)
{
    std::vector<std::string> result;
    
    // TODO: Implement here 
    
    std::string line;
     std::cout<<"Input a line:";
    while(std::getline(is,line,' '))
    { result.emplace_back(line);
     std::cout<<"Input a line:";}
     return result;
}

std::vector<IndexedString> parse(std::ifstream& is)
{
    std::vector<IndexedString> strings;
    
    // TODO: Implement here
    is("csv-file.csv");
    
    
    
    
    return strings;
}

void writeSentence(std::ostream& os, const std::vector<IndexedString>& strings)
{
    
    // TODO: Implement here 
    
    os << std::endl;
}



