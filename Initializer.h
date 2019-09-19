#include <iostream>

using namespace std;

class Initializer
{
  public:
    Initializer(); //default constructor

    void createWorld(); //runs all user i/o logic, and initializes world for use in game of life

    string input; //tracks user input

  private:
    void inputWorld(); //creates a world based on user input
    void randomWorld(); //creates a random world

    bool map; //tracks whether or not the user provides a map file themselves; true = yes, false = no
};
