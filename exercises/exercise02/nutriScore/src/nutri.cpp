/**
 * @file nutri.cpp
 */
#include "nutri.h"
#include<vector>
#include<iostream>

using Meal = std::tuple<std::string, char, size_t>;


const Meal& getUnhealthier(const Meal& mealA, const Meal& mealB)  {

    // TODO: Implement here
       using namespace std;
   if(get<1>(mealA)&&get<1>(mealB)=='E')
	   {if (get<2>(mealA)>get<2>(mealB))
		  return mealA;
		else 
		  return mealB;}
	  
   if(get<1>(mealA)&&get<1>(mealB)=='D')
        {if (get<2>(mealA)>get<2>(mealB))
	      return mealA;
		else 
	  	  return mealB;}
	   
  if(get<1>(mealA)=='E'&&get<1>(mealB)=='D')
     { if(get<2>(mealA)*2>get<2>(mealB))
	   return mealA;
	  else
	  return mealB;}
	  
  if(get<1>(mealA)=='D'&&get<1>(mealB)=='E')
     {if(get<2>(mealA)<get<2>(mealB)*2)
	    return mealB;
	  else
        return mealA;  }   
        return mealA;                    // You can change this line
}

void analyzeMeals(std::ostream& os, const std::vector<Meal>& meals)
{

    // TODO: Implement here
  
    int count=0,gesund=0;
    for(std::vector<Meal>::const_iterator iter=meals.begin();iter!=meals.end();++iter)
    {
		
		if(std::get<1>(meals[count])=='A'||std::get<1>(meals[count])=='B')      
		 gesund++;
	     count++;
	}   
	     
	os<<count<<"verschiedene Lebensmittel insgesamt verzehrt wurden"<<std::endl;
    os<<count<<"Von "<<count<< " Lebensmitteln waren "<<gesund<< " gesund"<<std::endl;   
	   
	   
      
   for(std::size_t i=0;i<meals.size()-1;i++)
	 {  Meal mealA=meals[i];  
    	Meal mealB=meals[i+1]; 
        Meal R=getUnhealthier(mealA, mealB);
        os<<"Es sollte lieber auf das Lebensmittel"<< std::get<0>(R)<<"verzichtet werden, es wurde "<< std::get<2>(R)<<"mal verzehrt"<<std::endl; } // You can change this line;
         
        
	    
    
}

