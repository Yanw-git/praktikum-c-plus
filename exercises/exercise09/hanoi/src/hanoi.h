/**
 * Header file for Tower and Hanoi
 */

#include <vector>
#include <functional>
#include <iostream>

class Tower
{
private:
    std::string name;
    std::vector<size_t> tower;

public:
    Tower();
    Tower(const std::string &name);                         // A,B,C
    Tower(const std::string &name, std::vector<size_t> &v); // towername ,und dessen elemante(tower=v)
    std::string &getName();
    std::vector<size_t> &getTower(); // get element of the tower
    friend std::ostream& operator<< (std::ostream&,Tower &);
};

class Hanoi
{
private:
    Tower towerA;
    Tower towerB;
    Tower towerC;

public:
    Hanoi(size_t height);
    void moveTopPlate(Tower &origin, Tower &target,
                      const std::function<void(const std::string &, const std::string &)> &preMovePrint,
                      const std::function<void()> &postMovePrint);
    void solveHanoiStart(std::ostream &os, Tower &source, Tower &destination, Tower &spare);
    void solveHanoi(size_t towersize, Tower &source, Tower &destination, Tower &spare,
                    const std::function<void(const std::string &, const std::string &)> &preMovePrint,
                    const std::function<void()> &postMovePrint);
};
