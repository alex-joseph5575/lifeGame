#include "MirrorMode.h"
#include "Initializer.h"
#include <iostream>
#include <unistd.h>
#include <fstream>

using namespace std;

//Constructor - sets defaults and loads in second grid
MirrorMode::MirrorMode()
{
  stable = false;
  Initializer* myInitializer = new Initializer();
  myGrid = myInitializer -> createWorld(); //take the grid from the Initializer class and use it here
  grid2 = new bool* [myInitializer -> rows]; //second grid for use in game logic

  //copy data from original grid to second grid
  for (int i = 0; i < myInitializer -> rows; ++i)
  {
    grid2[i] = new bool [myInitializer -> cols];
  }

  neighbors = 0;
  row = myInitializer -> rows;
  col = myInitializer -> cols;
  counter = 0;
  genCount = 0;
  modeType = myInitializer -> resultView;
}

//Destructor
MirrorMode::~MirrorMode()
{
  delete grid2;
}

//Runs game logic, advancing generations
void MirrorMode::runGame()
{
  //Loops through grid checking neighbors
  while (stable == false)
  {
    counter = 0;
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
            if (j == 0 || j == col - 1)
            {
              neighbors += 2;
            }
            else
            {
              ++neighbors;
            }
          }
          //top left corner special case
          if (j == 0)
          {
            //check space directly to the right
            if (col > 1 && myGrid[i][j + 1] == true)
            {
              neighbors += 2;
            }
            //check space diagonal down/right
            if (col > 1 && row > 1 && myGrid[i + 1][j + 1] == true)
            {
              ++neighbors;
            }
            //check self reflections
            if (myGrid[i][j] == true)
            {
              neighbors += 3;
            }
          }
          //top right corner special case
          else if (j == col - 1)
          {
            //check space directly to the left
            if (myGrid[i][j - 1] == true)
            {
              neighbors += 2;
            }
            //check space diagonal down/left
            if (row > 1 && myGrid[i + 1][j -1] == true)
            {
              ++neighbors;
            }
            //check self reflections
            if (myGrid[i][j] == true)
            {
              neighbors += 3;
            }
          }
          //general row 0 spaces
          else
          {
            //check space to the left
            if (myGrid[i][j - 1] == true)
            {
              neighbors += 2;
            }
            //check space to the right
            if (myGrid[i][j + 1] == true)
            {
              neighbors += 2;
            }
            //check space diagonal down/left
            if (row > 1 && myGrid[i + 1][j - 1] == true)
            {
              ++neighbors;
            }
            //check space diagonal down/right
            if (row > 1 && myGrid[i + 1][j + 1] == true)
            {
              ++neighbors;
            }
            //check self reflection
            if (myGrid[i][j] == true)
            {
              ++neighbors;
            }
          }
        }
        //bottom row special case
        else if (i == row - 1)
        {
          //Checks grid space directly above final row
          if (myGrid[i - 1][j] == true)
          {
            if (j == 0 || j == col - 1)
            {
              neighbors += 2;
            }
            else
            {
              ++neighbors;
            }
          }

          //bottom left corner special case
          if (j == 0)
          {
            //check space directly to the right
            if (col > 1 && myGrid[i][j + 1] == true)
            {
              neighbors += 2;
            }

            //check space diagonal top/right
            if (myGrid[i - 1][j + 1] == true)
            {
              ++neighbors;
            }

            //check self reflections
            if (myGrid[i][j] == true)
            {
              neighbors += 3;
            }
          }
          //bottom right corner special case
          else if (j == col - 1)
          {
            //check space directly to the left
            if (myGrid[i][j - 1] == true)
            {
              neighbors += 2;
            }
            //check space diagonal top/left
            if (myGrid[i - 1][j - 1] == true)
            {
              ++neighbors;
            }
            //check self reflections
            if (myGrid[i][j] == true)
            {
              neighbors += 3;
            }
          }
          //general final row spaces
          else
          {
            //check space to the left
            if (myGrid[i][j - 1] == true)
            {
              neighbors += 2;
            }
            //check space to the right
            if (myGrid[i][j + 1] == true)
            {
              neighbors += 2;
            }
            //check space diagonal top/left
            if (myGrid[i - 1][j - 1] == true)
            {
              ++neighbors;
            }
            //check space diagonal top/right
            if (myGrid[i - 1][j + 1] == true)
            {
              ++neighbors;
            }
            //check self reflection
            if (myGrid[i][j] == true)
            {
              ++neighbors;
            }
          }
        }
        //column 0 special case
        else if (j == 0)
        {
          //check space above
          if (myGrid[i - 1][j] == true)
          {
            neighbors += 2;
          }
          //check space below
          if (myGrid[i + 1][j] == true)
          {
            neighbors += 2;
          }
          //check space to the right
          if (col > 1 && myGrid[i][j + 1] == true)
          {
            ++neighbors;
          }
          //check space diagonal top right
          if (col > 1 && myGrid[i - 1][j + 1] == true)
          {
            ++neighbors;
          }
          //check space diagonal bottom right
          if (col > 1 && myGrid[i + 1][j + 1] == true)
          {
            ++neighbors;
          }
          //check self reflection
          if (myGrid[i][j] == true)
          {
            ++neighbors;
          }
        }
        //far right column special case
        else if (j == col - 1)
        {
          //check space directly above
          if (myGrid[i - 1][j] == true)
          {
            neighbors += 2;
          }
          //check space directly below
          if (myGrid[i + 1][j] == true)
          {
            neighbors += 2;
          }
          //check space to the left
          if (myGrid[i][j - 1] == true)
          {
            ++neighbors;
          }
          //check space diagonal top left
          if (myGrid[i - 1][j - 1] == true)
          {
            ++neighbors;
          }
          //check space diagonal bottom left
          if (myGrid[i + 1][j - 1] == true)
          {
            ++neighbors;
          }
          //check self reflection
          if (myGrid[i][j] == true)
          {
            ++neighbors;
          }
        }
        //general/non border space case
        else
        {
          //check above
          if (myGrid[i - 1][j] == true)
          {
            ++neighbors;
          }
          //check below
          if (myGrid[i + 1][j] == true)
          {
            ++neighbors;
          }
          //check left
          if (myGrid[i][j - 1] == true)
          {
            ++neighbors;
          }
          //check right
          if (myGrid[i][j + 1] == true)
          {
            ++neighbors;
          }
          //check diagonal up/left
          if (myGrid[i - 1][j - 1] == true)
          {
            ++neighbors;
          }
          //check diagonal up/right
          if (myGrid[i - 1][j + 1] == true)
          {
            ++neighbors;
          }
          //check diagonal down/left
          if (myGrid[i + 1][j - 1] == true)
          {
            ++neighbors;
          }
          //check diagonal down/right
          if (myGrid[i + 1][j + 1] == true)
          {
            ++neighbors;
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
        else
        {
          grid2 [i][j] = myGrid [i][j];
        }
      }
    }


    //pause between generations
    if (modeType == 1)
    {
      for (int i = 0; i < row; ++i)
      {
        for (int j = 0; j < col; ++j)
        {
          if (myGrid[i][j] == grid2[i][j])
          {
            ++counter;
          }

          myGrid[i][j] == grid2[i][j];

          if (myGrid[i][j] == true)
          {
            cout << "X";
          }
          else
          {
            cout << "-";
          }
        }
        cout << endl;
      }
      usleep(3000000);
    }

    //Press enter to continue
    else if (modeType == 2)
    {
      for (int i = 0; i < row; ++i)
      {
        for (int j = 0; j < col; ++j)
        {
          if (myGrid[i][j] == grid2[i][j])
          {
            ++counter;
          }

          myGrid[i][j] == grid2[i][j];

          if (myGrid[i][j] == true)
          {
            cout << "X";
          }
          else
          {
            cout << "-";
          }
        }
        cout << endl;
      }
      cin >> temp;
    }

    //output to file
    /*else if (modeType == 3)
    {
      writer.open(myInitializer -> fileName, std::ofstream::out | std::ofstream::app);
      for (int i = 0; i < row; ++i)
      {
        for (int j = 0; j < col; ++j)
        {
          if (myGrid[i][j] == grid2[i][j])
          {
            ++counter;
          }

          myGrid[i][j] == grid2[i][j];

          if (myGrid[i][j] == true)
          {
            writer.write('X');
          }
          else
          {
            writer.write('-');
          }
        }
        writer.write('\n');
      }
      writer.close();
    }*/

    //If all spaces are identical between the 2 grids, add to gencount
    if (counter == row * col)
    {
      ++genCount;
    }

    //If 3 or more generations are the same, assume game is stable
    if (genCount >= 3)
    {
      cout << "The grid has stabilized. Exiting program." << endl;
      stable = true;
    }

    ++generations;

    //check every 20 generations in case grid is fluctuating back and forth endlessly
    if (generations % 20 == 0)
    {
      cout << "1) Continue simulation" << endl;
      cout << "2) Exit program" << endl;
      cin >> temp;
      cout << endl;

      if (temp == "2")
      {
        cout << "Exiting program." << endl;
        exit(0);
      }
    }
  }
}
