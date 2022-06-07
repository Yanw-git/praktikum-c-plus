/**
 * @file show.cpp
 */
#include <iostream>
#include <random>
#include <cassert>
#include "show.h"


static std::random_device rd;
std::default_random_engine Show::re(rd());   //defination static member

Show::Show()
{
    std::uniform_int_distribution<int> dist(1, 3);
    carDoor = dist(re);
}


int Show::showGoatDoor(int firstGuess)
{
    // TODO: Implement Show::getGoatDoor here
    // Dummy:
   if(firstGuess!=carDoor)
     { std::uniform_int_distribution<int> dist(1,3);
	   int Renumber;
		while(1)
		{
          Renumber=dist(re);
          //std::cout<<"carDoor="<<carDoor<<std::endl;
          //std::cout<<"Renumber="<<Renumber<<std::endl;
		  //std::cout<<"goatDoor="<<firstGuess<<std::endl;
		  if(Renumber!=carDoor&&Renumber!=firstGuess)
		   break;
		}
         return Renumber;
	  }
   else if(firstGuess==carDoor)
    { std::uniform_int_distribution<int> dist(1,3);
      int Renumber;
       while(1)
       { 
		   Renumber=dist(re);
		   //std::cout<<"Renumber="<<Renumber<<std::endl;
		   //std::cout<<"carDoor="<<carDoor<<std::endl;
	   	   if(Renumber!=carDoor)
		   break;
	   }		
	return Renumber;
    }
    return 0;
}



