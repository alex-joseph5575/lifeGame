#include <iostream>

using namespace std;

class ClassicMode
{
  public:
    ClassicMode();  //default constructor
    ~ClassicMode(); //destructor

    void runGame(); //handles game logic and cycles through generations


  private:
    void appendResults(); //appends results of game to file as output

    void swap(bool** a, bool** b); //swaps the object two pointers are pointing at

    bool** myGrid; //game grid
    bool** grid2; //second grid used in game logic
    bool stable; //indicates whether world is stable or not
    short neighbors; //number of neighbors of given cell
    short row; //number of rows...again
    short col; //number of columns since my compiler is shitting the bed



};
