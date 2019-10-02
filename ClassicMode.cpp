#include "ClassicMode.h"
#include "Initializer.h"
#include <iostream>
#include <unistd.h>
#include <fstream>

using namespace std;

//Constructor - sets defaults and loads in second grid
ClassicMode::ClassicMode()
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
  file = myInitializer -> fileName;
}

//Destructor
ClassicMode::~ClassicMode()
{
  delete grid2;
}

//Runs game logic, advancing generations
void ClassicMode::runGame()
{
  if (modeType == 1 || modeType == 2)
  {
    cout << "Initial board: " << endl;
    for (int i = 0; i < row; ++i)
    {
      for (int j = 0; j < col; ++j)
      {
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
    cout << endl;
  }
  else
  {
    writer.open(file, ios_base::app);
    writer << "Initial board: \n";
    for (int i = 0; i < row; ++i)
    {
      for (int j = 0; j < col; ++j)
      {
        if (myGrid[i][j] == true)
        {
          writer << "X";
        }
        else
        {
          writer << "-";
        }
      }
      writer << '\n';
    }
    writer << '\n';
    writer.close();
  }
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
            ++neighbors;
          }
          //top left corner special case
          if (j == 0)
          {
            //check space directly to the right
            if (col > 1 && myGrid[i][j + 1] == true)
            {
              ++neighbors;
            }
            //check space diagonal down/right
            if (col > 1 && row > 1 && myGrid[i + 1][j + 1] == true)
            {
              ++neighbors;
            }
          }
          //top right corner special case
          else if (j == col - 1)
          {
            //check space directly to the left
            if (myGrid[i][j - 1] == true)
            {
              ++neighbors;
            }
            //check space diagonal down/left
            if (row > 1 && myGrid[i + 1][j -1] == true)
            {
              ++neighbors;
            }
          }
          //general row 0 spaces
          else
          {
            //check space to the left
            if (myGrid[i][j - 1] == true)
            {
              ++neighbors;
            }
            //check space to the right
            if (myGrid[i][j + 1] == true)
            {
              ++neighbors;
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
          }
        }
        //bottom row special case
        else if (i == row - 1)
        {
          //Checks grid space directly above final row
          if (myGrid[i - 1][j] == true)
          {
            ++neighbors;
          }

          //bottom left corner special case
          if (j == 0)
          {
            //check space directly to the right
            if (col > 1 && myGrid[i][j + 1] == true)
            {
              ++neighbors;
            }

            //check space diagonal top/right
            if (myGrid[i - 1][j + 1] == true)
            {
              ++neighbors;
            }
          }
          //bottom right corner special case
          else if (j == col - 1)
          {
            //check space directly to the left
            if (myGrid[i][j - 1] == true)
            {
              ++neighbors;
            }
            //check space diagonal top/left
            if (myGrid[i - 1][j - 1] == true)
            {
              ++neighbors;
            }
          }
          //general final row spaces
          else
          {
            //check space to the left
            if (myGrid[i][j - 1] == true)
            {
              ++neighbors;
            }
            //check space to the right
            if (myGrid[i][j + 1] == true)
            {
              ++neighbors;
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
          }
        }
        //column 0 special case
        else if (j == 0)
        {
          //check space above
          if (myGrid[i - 1][j] == true)
          {
            ++neighbors;
          }
          //check space below
          if (myGrid[i + 1][j] == true)
          {
            ++neighbors;
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
        }
        //far right column special case
        else if (j == col - 1)
        {
          //check space directly above
          if (myGrid[i - 1][j] == true)
          {
            ++neighbors;
          }
          //check space directly below
          if (myGrid[i + 1][j] == true)
          {
            ++neighbors;
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


    //Output grid
    writer.open(file, ios_base::app);
    for (int i = 0; i < row; ++i)
    {
      for (int j = 0; j < col; ++j)
      {
        if (myGrid[i][j] == grid2[i][j])
        {
          ++counter;
        }

        myGrid[i][j] = grid2[i][j];

        if (modeType == 1 || modeType == 2)
        {
          if (myGrid[i][j] == true)
          {
            cout << "X";
          }
          else
          {
            cout << "-";
          }
        }
        else
        {
          if (myGrid[i][j] == true)
          {
            writer << 'X';
          }
          else
          {
            writer << '-';
          }
        }
      }
      if (modeType == 1 || modeType == 2)
      {
        cout << endl;
      }
      else
      {
        writer << '\n';
      }
    }
    if (modeType == 1 || modeType == 2)
    {
      cout << endl;
    }
    else
    {
      writer << '\n';
    }
    writer.close();

    if (modeType == 1)
    {
      usleep(3000000);
    }
    else if (modeType == 2)
    {
      cin >> temp;
    }

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
      cout << "Generations passed: " << generations << endl;
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
