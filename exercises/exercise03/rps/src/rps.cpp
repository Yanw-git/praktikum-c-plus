/**
 * @file rps.cpp
 */
#include "rps.h"
#include <sstream>


Move parseInput(const std::string& input) {

    // TODO: Implement here
 if(input=="rock")
   return Move::Rock;
 else if(input=="paper")
   return Move::Paper;
 else if( input== "scissors") 
    return Move::Scissors;
 else
	  return Move::Error;  
}


Result rockPaperScissors(const std::string& p1, const std::string& p2) {

    // TODO: Implement here
    
    Move R1,R2;
    R1=parseInput(p1);
    R2=parseInput(p2);
   
     while(R1!=Move::Error&&R2!=Move::Error)
    {
	   if(R1==Move::Rock&&R2==Move::Paper)
	       //std::cout<<"Player2Wins"<<std::endl;
	         return Result::Player2Wins;
	    else if(R1==Move::Paper&&R2==Move::Rock)
	       //std::cout<<"Player1Wins"<<std::endl;
	        return Result::Player1Wins;
	    else if(R1==Move::Paper&&R2==Move::Scissors)
	       //std::cout<<"Player2Wins"<<std::endl;
	         return Result::Player2Wins;
	    else if(R1==Move::Scissors&&R2==Move::Paper)
	       //std::cout<<"Player1Wins"<<std::endl;
	       return Result::Player1Wins;
		else if(R1==Move::Rock&&R2==Move::Scissors)
		      return Result::Player1Wins;
		   //std::cout<<"Player1Wins"<<std::endl;
	    else if(R1==Move::Scissors&&R2==Move::Rock)
	       //std::cout<<"Player2Wins"<<std::endl;
	       return Result::Player2Wins;  
		else                                  //R1==R2
		   //std::cout<<"Tie"<<std::endl;
		   return Result::Tie;	
	   }

    if(R1==Move::Error||R2==Move::Error)
       //std::cout<<"Invalid"<<std::endl;
       	   return Result::Invalid;	
      return Result::Invalid;
}

int main(int argc, char** argv) {
    std::vector<std::string> args(argv, argv + argc);

    // TODO: Add code here
   std::cout<<args[1]<<std::endl;             
   std::cout<<args[2]<<std::endl;
   std::string p1=args[1];
   std::string p2=args[2];
   //std::cout<<"Player1:"<<args[1]<<std::endl;
   //std::cout<<"Player2:"<<args[2]<<std::endl;

    Result Ergebnis;
    Ergebnis=rockPaperScissors(p1,p2);
    if(Ergebnis==Result::Player1Wins)
    std::cout <<"Player1Wins"<< std::endl;
    if(Ergebnis==Result::Player2Wins)
    std::cout <<"Player2Wins"<< std::endl;
    if(Ergebnis==Result::Tie)
    std::cout <<"Tie"<< std::endl;
    if(Ergebnis==Result::Invalid)
    std::cout <<"Invalid Input"<< std::endl;
    
    return 0;
}





