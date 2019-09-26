#include "ClassicMode.h"
#include "Initializer.h"
#include <iostream>

using namespace std;

ClassicMode::ClassicMode()
{
  stable = false;
  Initializer myInitializer;
  myGrid = myInitializer.createWorld();
  grid2 = new bool* [myInitializer.rows];
  for (int i = 0; i < myInitializer.rows; ++i)
  {
    grid2[i] = new bool [myInitializer.cols];
  }
  neighbors = 0;
  row = myInitializer.rows;
  col = myInitializer.cols;
}

ClassicMode::~ClassicMode()
{
  delete grid2;
}

void ClassicMode::runGame()
{
  //Loops through grid checking neighbors
  while (stable == false)
  {
    //iterates through each row
    for (int i = 0; i < row; ++i)
    {
      //iterates through each column
      for (int j = 0; j < col; ++j)
      {
        //extra case if on row 0
        if (i == 0)
        {
          //Checks grid space directly below row 0
          if (row > 1 && myGrid[i + 1][j] == true)
          {
            ++neighbors;
            // if 4 or more neighbors, automatically continue to next loop iteration
            if (neighbors >= 4)
            {
              grid2 [i][j] = false;
              continue;
            }
          }

          //top left corner special case
          if (j == 0)
          {
            if (col > 1 && myGrid [i][j + 1] == true)
            {
              ++neighbors;
              // if 4 or more neighbors, automatically continue to next loop iteration
              if (neighbors >= 4)
              {
                grid2 [i][j] = false;
                continue;
              }
            }
          }
        }

      }
    }
  }
}

void ClassicMode::appendResults()
{

}
