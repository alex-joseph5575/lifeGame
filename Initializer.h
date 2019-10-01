#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class Initializer
{
  public:
    Initializer(); //default constructor
    ~Initializer(); //destructor

    bool** createWorld(); //runs all user i/o logic, and initializes world for use in game of life

    string input; //tracks user input
    int rows; //number of rows in the grid
    int cols; //number of columns in the grid
    fstream fileStream; //deals with input and output with files
    bool** grid; //representation of game grid
    short resultView; //representation of how the user would like to view each generation
    string fileName; //name of output file

  private:
    bool** createMap(); //creates a world based on user input
    bool** randomMap(); //creates a random world

    bool map; //tracks whether or not the user provides a map file themselves; true = yes, false = no

};
