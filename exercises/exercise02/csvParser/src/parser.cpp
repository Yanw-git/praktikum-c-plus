/**
 * @file parser.cpp
 */
#include "parser.h"
#include <sstream>


std::vector<std::string> split(std::istream& is, char delim)

{
    std::vector<std::string> result;
    
    // TODO: Implement here 
    
    std::string line;
     std::cout<<"Input a line:";
    while(std::getline(is,line,';'))
    { 
	 result.emplace_back(line);
     
     }
     return result;
}

std::vector<IndexedString> parse(std::istream& is)
{
    std::vector<IndexedString> strings;
    
    // TODO: Implement here
     char delim=';';
     std::vector<int> b;
     std::vector<std::string> a=split(is, delim);
     for(std::size_t i=0;i<a.size();i+=2)
     {
	    
	   b.emplace_back(std::stoi(a[i],0,10));
	}
	  for(std::size_t i=0,j=1;i<(a.size()/2);i+=2,j+=2)
	  {
        strings.emplace_back(b[i],a[j]);
	  }
   
    
   
    return strings;
}

#define DEBUG
#ifndef DEBUG
void writeSentence(std::ostream& os, const std::vector<IndexedString>& strings)
{
    
    // TODO: Implement here 
    
    os << std::endl;
}

#endif

