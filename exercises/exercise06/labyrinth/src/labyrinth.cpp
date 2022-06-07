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
    current->visit();  //predecessors[0].xPos
    //Implement this function
#if true
    std::vector<int> x_shift{ 0,-1,1,0 };
    std::vector<int> y_shift{ -1,0,0,1 };
#else
    std::vector<int> x_shift{ -1,0,1,-1,1,-1,0,1 };
    std::vector<int> y_shift{ -1,-1,-1,0,0,1,1,1 };
#endif
    for (size_t i = 0; i != x_shift.size(); ++i)
    {
        int tmp_x = x + x_shift[i], tmp_y = y + y_shift[i];
        if (tmp_x < 0 || tmp_y < 0 || tmp_x >= floor[0].size() || tmp_y >= floor.size()) 
         continue;
        if (!floor[tmp_y][tmp_x].isBarrier() || !floor[tmp_y][tmp_x].isVisited())
        {
            pending.push(&floor[tmp_y][tmp_x]);
            predecessors[tmp_y][tmp_x] = current;
        }
    }

}
    


void Labyrinth::searchShortestPath()
{
    std::queue<Tile*> pending;
    std::vector<std::vector<Tile*>> predecessors(this->floor.size(), std::vector<Tile*>(this->floor[0].size(), nullptr));
    //Implement here
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


