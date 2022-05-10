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
    std::ifstream read1(arguments[1]);       //oeffnen Datein arg1=1.txt
    std::ifstream read2(arguments[2]);
    std::vector<std::string> c1;
    std::vector<std::string> c2;
    std::string line;
    while(std::getline(read1,line))      //zeilenweise lesen 1.txt ein
      c1.emplace_back(line);
    while(std::getline(read2,line))
      c2.emplace_back(line);
    compareFilesLineByLine(c1,c2);                            
    
    
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
	if (lines1.size()<=lines2.size())               //txt.vorne<txt hinten
	 { for(std::size_t i=0;i<lines1.size();++i)    
	    {
		   if(lines1[i]!=lines2[i])
			  {std::cout<<"<<<"<<(i+1)<<"<<<"<<lines1[i]<<std::endl;
			   std::cout<<">>>"<<(i+1)<<">>>"<<lines2[i]<<std::endl;	
			   }
		}	 
	for(std::size_t j=lines1.size();j<lines2.size();++j)
	    {
		   std::cout<<">>>"<<(j+1)<<">>>"<<lines2[j]<<std::endl;
		}  
	  } 
	  
	else                                //txt vorne>txt hinten
	{ for(std::size_t i=0;i<lines2.size();++i)    
	    {
		   if(lines1[i]!=lines2[i])
			  {std::cout<<"<<<"<<(i+1)<<"<<<"<<lines1[i]<<std::endl;
			   std::cout<<">>>"<<(i+1)<<">>>"<<lines2[i]<<std::endl;	
			   }
		}	 
	for(std::size_t j=lines2.size();j<lines1.size();++j)
	    {
		   std::cout<<">>>"<<(j+1)<<">>>"<<lines1[j]<<std::endl;
		}  
	  } 
		 	 
}    
#endif

