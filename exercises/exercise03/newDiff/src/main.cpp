#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#define NOBONUS

void compareFilesLineByLine(const std::vector<std::string>&,
                            const std::vector<std::string>&);

int main(int argc, char** argv)
{
    std::vector<std::string> arguments(argv, argv + argc);
    // Implement here
    std::ifstream read1(arguments[1]);       //oeffen Datein arg1? 
    std::ifstream read2(arguments[2]);
    std::string line;
    while(std::getline(read1,line))      //zeilenweise?
    
    
    
    
    
    
    return 0;
}

#if defined(NOBONUS)
void compareFilesLineByLine(const std::vector<std::string>& lines1,
                            const std::vector<std::string>& lines2)
{
    // Implement here
}          
#else

void compareFilesLineByLine(const std::vector<std::string>& lines1,
                            const std::vector<std::string>& lines2)    
{
    // Implement here
}    
#endif


