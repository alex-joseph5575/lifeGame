#include <iostream>
#include <fstream>

using namespace std;

class ClassicMode
{
  public:
    ClassicMode();  //default constructor
    ~ClassicMode(); //destructor

    void runGame(); //handles game logic and cycles through generations


  private:
    bool** myGrid; //game grid
    bool** grid2; //second grid used in game logic
    bool stable; //indicates whether world is stable or not
    short row; //number of rows...again
    short col; //number of columns since my compiler is shitting the bed
    short counter; //counts identical grid spaces
    short genCount; //counts how many generations have been identical
    short generations; //number of generations iterated through in the game so far
    short modeType; //represents which type of output the user has selected
    short neighbors;
    string temp; //temp input to advance simulation
    string file; //name of file to output to 
    ofstream writer; //writes to output file



};
