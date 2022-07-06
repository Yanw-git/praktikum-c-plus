/**
 * Implementation of Tower and Hanoi
 */

#include <algorithm>
#include <stack>
#include <deque>
#include "hanoi.h"

std::string &Tower::getName()
{
    return this->name;
}

std::vector<size_t> &Tower::getTower()
{
    return this->tower; // std::vector<size_t> tower
}

Tower::Tower() {}

Tower::Tower(const std::string &name) : name(name), tower(std::vector<size_t>()) {}

Tower::Tower(const std::string &name, std::vector<size_t> &v) : name(name), tower(v) {}

Hanoi::Hanoi(size_t height)
{

    this->towerA = Tower("TowerA"); // Hanoiobject.towerA=towerA(string name "TowerA")  
    for (size_t i = height; i > 0; --i)
        this->towerA.getTower().push_back(i);  //Hanoiobject.towerA(member),Hanoi hat Instanz towerA(of andere class) als eigene Datenmember
    this->towerC = Tower("TowerC");
    this->solveHanoiStart(std::cout, this->towerA, this->towerB, this->towerC);
}

std::ostream& operator<< (std::ostream& os,Tower & t)
{
    os<<t.getName()<<std::endl;
    for(auto& i: t.getTower())
    {
        os<<i<<",";
    }
    return os;
}


void Hanoi::moveTopPlate(Tower &origin, Tower &target,
                         const std::function<void(const std::string &, const std::string &)> &preMovePrint,
                         const std::function<void()> &postMovePrint) //Referenz of postMovePrint variable
{ 
    // TODO: Implement
    preMovePrint(origin.getName(),target.getName());
    if(origin.getTower().back()<target.getTower().back()) 
     {
        target.getTower().push_back(origin.getTower().back());
        origin.getTower().pop_back();
     }
    postMovePrint();
}

void Hanoi::solveHanoi(size_t towersize, Tower &source, Tower &destination, Tower &spare,  //vector.size(),string name:towerA,towerB,towerC
                       const std::function<void(const std::string &, const std::string &)> &preMovePrint,
                       const std::function<void()> &postMovePrint)
{
    // TODO: Implement
    if(towersize==1)
     { 
      //moveTopPlate(source,destination,preMovePrint,postMovePrint);
    
        destination.getTower().push_back(source.getTower().back());
        source.getTower().pop_back(); 
     }
    else
    {
    solveHanoi(towersize-1,source,spare,destination,preMovePrint,postMovePrint);
    moveTopPlate(source,destination,preMovePrint,postMovePrint);
    solveHanoi(towersize-1,spare,destination,source,preMovePrint,postMovePrint);}
}


void Hanoi::solveHanoiStart(std::ostream &os, Tower &source, Tower &destination, Tower &spare) //cout,string name:towerA,towerB,towerC
{
    // TODO: Implement
auto preMovePrint = [&os](const std::string & originname, const std::string & targetname){ //Lambda speichert in einer Variable mit auto!
    os<<"originname is  "<<originname<<", "<<"targetname is  "<<targetname<<std::endl;
    };
auto postMovePrint=[&os,&source,&destination, &spare](){ 
     os<<"source:"<<source<<std::endl;
     os<<"destination:"<<destination<<std::endl;
     os<<"spare:"<<spare<<std::endl;
     
   };

solveHanoi(source.getTower().size(), source, destination, spare, preMovePrint, postMovePrint);
}
