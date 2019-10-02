#include <iostream>
#include <fstream>

using namespace std;

class DoughnutMode
{
  public:
    DoughnutMode();  //default constructor
    ~DoughnutMode(); //destructor

    void runGame(); //handles game logic and cycles through generations


  private:
    bool** myGrid; //game grid
    bool** grid2; //second grid used in game logic
    bool stable; //indicates whether world is stable or not
    short neighbors; //number of neighbors of given cell
    short row; //number of rows...again
    short col; //number of columns since my compiler is shitting the bed
    short counter; //counts identical grid spaces
    short genCount; //counts how many generations have been identical
    short generations; //number of generations iterated through in the game so far
    short modeType; //represents which type of output the user has selected
    string temp; //temp input to advance simulation
    ofstream writer; //writes to output file
    string file; //name of file to output to 



};
