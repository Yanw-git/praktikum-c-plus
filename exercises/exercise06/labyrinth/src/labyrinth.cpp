#include "labyrinth.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>

Tile* Labyrinth::getOrigin()
{
    //Implement this function
    size_t x;    //xPos
    size_t y;    //yPos 
    for(x=0;x<floor.size();++x)       
      for(y=0;y<floor[x].size();++y)    
      {    if(floor[x][y].isOrigin())
		   return &floor[x][y];
	  }
	  return getOrigin();
}

/** Helper function that is supposed to be used to process the neighbors of a Tile. */
void emplaceNeighbor(std::vector<std::vector<Tile>>& floor,
                     std::vector<std::vector<Tile*>>& predecessors,
                     std::queue<Tile*>& pending,
                     Tile* current, size_t x, size_t y)           
{
    //Implement this function
    std::vector<int> x_move={-1,0,1,0};
    std::vector<int> y_move={0,-1,0,1};
    for(int i=0;i<4;++i)
    {   auto x_new=x+x_move[i];
        auto y_new=y+y_move[i];
      if(!floor[x_new][y_new].isBarrier()&&!floor[x_new][y_new].isVisited())
      {
		  pending.push(&floor[x_new][y_new]);
		  current->visit();
		  predecessors[x_new][y_new]=current;
	  }
    }
}


void Labyrinth::searchShortestPath()
{
    std::queue<Tile*> pending;
    std::vector<std::vector<Tile*>> predecessors(this->floor.size(), std::vector<Tile*>(this->floor[0].size(), nullptr));
    //Implement here
    Tile* Origin=this->getOrigin();
    pending.push(Origin);
    predecessors[Origin->getX()][Origin->getY()] = Origin;
     while (!pending.empty())         //pending not empty
    { 
        Tile* current = pending.front();
        pending.pop();
        if (current->isDestination())
        {
            backTrack(floor,predecessors, current);
            break;
        }
        size_t x = current->getX(), y = current->getY();
        emplaceNeighbor(floor, predecessors, pending, current, x, y);
    }
    
}

void Labyrinth::backTrack(std::vector<std::vector<Tile>>& floor, std::vector<std::vector<Tile*>>& predecessors, Tile* current)
{
	while(1)
    {
		if (current->isOrigin()) break;
        int cur_x = current->getX(), cur_y = current->getY();
        floor[cur_x][cur_y].addToPath();
        current = predecessors[cur_x][cur_y];
	}
}
 

void Labyrinth::printLabyrinth(std::ostream& os, bool visualizeVisited) const
{
    for(const std::vector<Tile>& row: this->floor)
    {
        for(const Tile& tile: row)
            tile.print(os, visualizeVisited);
        os<<"\n";
    }
}


