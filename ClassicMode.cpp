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
        neighbors = 0;
        //top row special case
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
            //check space directly to the right
            if (col > 1 && myGrid[i][j + 1] == true)
            {
              ++neighbors;
              // if 4 or more neighbors, automatically continue to next loop iteration
              if (neighbors >= 4)
              {
                grid2 [i][j] = false;
                continue;
              }
            }
            //check space diagonal down/right
            if (col > 1 && row > 1 && myGrid[i + 1][j + 1] == true)
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
          //top right corner special case
          else if (j == col - 1)
          {
            //check space directly to the left
            if (myGrid[i][j - 1] == true)
            {
              ++neighbors;
              // if 4 or more neighbors, automatically continue to next loop iteration
              if (neighbors >= 4)
              {
                grid2 [i][j] = false;
                continue;
              }
            }
            //check space diagonal down/left
            if (row > 1 && myGrid[i + 1][j -1] == true)
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
          //general row 0 spaces
          else
          {
            //check space to the left
            if (myGrid[i][j - 1] == true)
            {
              ++neighbors;
              // if 4 or more neighbors, automatically continue to next loop iteration
              if (neighbors >= 4)
              {
                grid2 [i][j] = false;
                continue;
              }
            }
            //check space to the right
            if (myGrid[i][j + 1] == true)
            {
              ++neighbors;
              // if 4 or more neighbors, automatically continue to next loop iteration
              if (neighbors >= 4)
              {
                grid2 [i][j] = false;
                continue;
              }
            }
            //check space diagonal down/left
            if (row > 1 && myGrid[i + 1][j - 1] == true)
            {
              ++neighbors;
              // if 4 or more neighbors, automatically continue to next loop iteration
              if (neighbors >= 4)
              {
                grid2 [i][j] = false;
                continue;
              }
            }
            //check space diagonal down/right
            if (row > 1 && myGrid[i + 1][j + 1] == true)
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
        //bottom row special case
        else if (i == row - 1)
        {
          //Checks grid space directly above final row
          if (myGrid[i - 1][j] == true)
          {
            ++neighbors;
            // if 4 or more neighbors, automatically continue to next loop iteration
            if (neighbors >= 4)
            {
              grid2 [i][j] = false;
              continue;
            }
          }

          //bottom left corner special case
          if (j == 0)
          {
            //check space directly to the right
            if (col > 1 && myGrid[i][j + 1] == true)
            {
              ++neighbors;
              // if 4 or more neighbors, automatically continue to next loop iteration
              if (neighbors >= 4)
              {
                grid2 [i][j] = false;
                continue;
              }
            }

            //check space diagonal top/right
            if (myGrid[i - 1][j + 1] == true)
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
          //bottom right corner special case
          else if (j == col - 1)
          {
            //check space directly to the left
            if (myGrid[i][j - 1] == true)
            {
              ++neighbors;
              // if 4 or more neighbors, automatically continue to next loop iteration
              if (neighbors >= 4)
              {
                grid2 [i][j] = false;
                continue;
              }
            }
            //check space diagonal top/left
            if (myGrid[i - 1][j - 1] == true)
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
          //general final row spaces
          else
          {
            //check space to the left
            if (myGrid[i][j - 1] == true)
            {
              ++neighbors;
              // if 4 or more neighbors, automatically continue to next loop iteration
              if (neighbors >= 4)
              {
                grid2 [i][j] = false;
                continue;
              }
            }
            //check space to the right
            if (myGrid[i][j + 1] == true)
            {
              ++neighbors;
              // if 4 or more neighbors, automatically continue to next loop iteration
              if (neighbors >= 4)
              {
                grid2 [i][j] = false;
                continue;
              }
            }
            //check space diagonal top/left
            if (myGrid[i - 1][j - 1] == true)
            {
              ++neighbors;
              // if 4 or more neighbors, automatically continue to next loop iteration
              if (neighbors >= 4)
              {
                grid2 [i][j] = false;
                continue;
              }
            }
            //check space diagonal top/right
            if (myGrid[i - 1][j + 1] == true)
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
        //column 0 special case
        else if (j == 0)
        {
          //check space above
          if (myGrid[i - 1][j] == true)
          {
            ++neighbors;
            // if 4 or more neighbors, automatically continue to next loop iteration
            if (neighbors >= 4)
            {
              grid2 [i][j] = false;
              continue;
            }
          }
          //check space below
          if (myGrid[i + 1][j] == true)
          {
            ++neighbors;
            // if 4 or more neighbors, automatically continue to next loop iteration
            if (neighbors >= 4)
            {
              grid2 [i][j] = false;
              continue;
            }
          }
          //check space to the right
          if (col > 1 && myGrid[i][j + 1] == true)
          {
            ++neighbors;
            // if 4 or more neighbors, automatically continue to next loop iteration
            if (neighbors >= 4)
            {
              grid2 [i][j] = false;
              continue;
            }
          }
          //check space diagonal top right
          if (col > 1 && myGrid[i - 1][j + 1] == true)
          {
            ++neighbors;
            // if 4 or more neighbors, automatically continue to next loop iteration
            if (neighbors >= 4)
            {
              grid2 [i][j] = false;
              continue;
            }
          }
          //check space diagonal bottom right
          if (col > 1 && myGrid[i + 1][j + 1] == true)
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
        //far right column special case
        else if (j == col - 1)
        {
          //check space directly above
          if (myGrid[i - 1][j] == true)
          {
            ++neighbors;
            // if 4 or more neighbors, automatically continue to next loop iteration
            if (neighbors >= 4)
            {
              grid2 [i][j] = false;
              continue;
            }
          }
          //check space directly below
          if (myGrid[i + 1][j] == true)
          {
            ++neighbors;
            // if 4 or more neighbors, automatically continue to next loop iteration
            if (neighbors >= 4)
            {
              grid2 [i][j] = false;
              continue;
            }
          }
          //check space to the left
          if (myGrid[i][j - 1] == true)
          {
            ++neighbors;
            // if 4 or more neighbors, automatically continue to next loop iteration
            if (neighbors >= 4)
            {
              grid2 [i][j] = false;
              continue;
            }
          }
          //check space diagonal top left
          if (myGrid[i - 1][j - 1] == true)
          {
            ++neighbors;
            // if 4 or more neighbors, automatically continue to next loop iteration
            if (neighbors >= 4)
            {
              grid2 [i][j] = false;
              continue;
            }
          }
          //check space diagonal bottom left
          if (myGrid[i + 1][j - 1] == true)
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
        //general/non border space case
        else
        {
          //check above
          if (myGrid[i - 1][j] == true)
          {
            ++neighbors;
            // if 4 or more neighbors, automatically continue to next loop iteration
            if (neighbors >= 4)
            {
              grid2 [i][j] = false;
              continue;
            }
          }
          //check below
          if (myGrid[i + 1][j] == true)
          {
            ++neighbors;
            // if 4 or more neighbors, automatically continue to next loop iteration
            if (neighbors >= 4)
            {
              grid2 [i][j] = false;
              continue;
            }
          }
          //check left
          if (myGrid[i][j - 1] == true)
          {
            ++neighbors;
            // if 4 or more neighbors, automatically continue to next loop iteration
            if (neighbors >= 4)
            {
              grid2 [i][j] = false;
              continue;
            }
          }
          //check right
          if (myGrid[i][j + 1] == true)
          {
            ++neighbors;
            // if 4 or more neighbors, automatically continue to next loop iteration
            if (neighbors >= 4)
            {
              grid2 [i][j] = false;
              continue;
            }
          }
          //check diagonal up/left
          if (myGrid[i - 1][j - 1] == true)
          {
            ++neighbors;
            // if 4 or more neighbors, automatically continue to next loop iteration
            if (neighbors >= 4)
            {
              grid2 [i][j] = false;
              continue;
            }
          }
          //check diagonal up/right
          if (myGrid[i - 1][j + 1] == true)
          {
            ++neighbors;
            // if 4 or more neighbors, automatically continue to next loop iteration
            if (neighbors >= 4)
            {
              grid2 [i][j] = false;
              continue;
            }
          }
          //check diagonal down/left
          if (myGrid[i + 1][j - 1] == true)
          {
            ++neighbors;
            // if 4 or more neighbors, automatically continue to next loop iteration
            if (neighbors >= 4)
            {
              grid2 [i][j] = false;
              continue;
            }
          }
          //check diagonal down/right
          if (myGrid[i + 1][j + 1] == true)
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

        //determine space for next generation
        if (neighbors <= 1 || neighbors >= 4)
        {
          grid2 [i][j] = false;
        }
        else if (neighbors == 3)
        {
          grid2 [i][j] = true;
        }
      }
    }
  }
}

void ClassicMode::appendResults()
{

}
