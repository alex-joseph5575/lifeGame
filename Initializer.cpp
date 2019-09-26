#include "Initializer.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

Initializer::Initializer()
{

}

Initializer::~Initializer()
{
  delete grid;
}

bool** Initializer::createWorld()
{
  cout << "Would you like to provide a map file?" << endl;
  while (true)
  {
    cout << "1) Yes" << endl;
    cout << "2) No" << endl;
    cout << "3) Exit" << endl;
    getline(cin, input);
    cout << endl;

    if (input == "1" || input == "Yes" || input == "YES" || input == "yes")
    {
      map = true;
      break;
    }

    else if (input == "2" || input == "No" || input == "NO" || input == "no")
    {
      map = false;
      break;
    }
    else if (input == "3" || input == "Exit" || input == "EXIT" || input == "exit")
    {
      cout << "Have a nice day!" << endl;
      exit(0);
    }
    else
    {
      cout << "Invalid input. Please select one of the provided options." << endl;
    }
  }

  cout << "Before the game starts, how would you like to view the results?" << endl;
  while (true)
  {
    cout << "1) Have a pause between each generation" << endl;
    cout << "2) Manually press enter to advance a generation" << endl;
    cout << "3) Output results to a file" << endl;
    cout << "4) Exit program" << endl;

    getline(cin, input);
    cout << endl;
    if (input == "1")
    {
      resultView = 1;
      break;
    }
    else if (input == "2")
    {
      resultView = 2;
      break;
    }
    else if (input == "3")
    {
      resultView = 3;
      break;
    }
    else if (input == "4")
    {
      exit(0);
    }
    else
    {
      cout << "Invalid input. Please choose one of the 4 options." << endl;
    }
  }

  if (map == true)
  {
    //return createMap();
  }

  else
  {
    return randomMap();
  }
}

bool** Initializer::createMap()
{
  /*string tempLine;
  cout << "Please enter the file path of your map." << endl;
  while (true)
  {
    getline(cin, input);
    cout << endl;
    fileStream.open(input);

    if (fileStream.fail())
    {
      cout << "Invalid file name, please input a different file." << endl;
    }
    else
    {
      break;
    }
  }
  fileStream.getline(tempLine, 1);*/
}

bool** Initializer::randomMap()
{
  float density;
  float random;
  cout << "How many rows?" << endl;
  cin >> rows;
  cout << endl;
  cout << "How many columns?" << endl;
  cin >> cols;
  cout << endl;
  grid = new bool* [rows];

  for (int i = 0; i < rows; ++i)
  {
    grid[i] = new bool [cols];
  }

  cout << "Enter the population density as a decimal greater than 0 and less than or equal to 1" << endl;
  cin >> density;
  cout << endl;

  srand(time(NULL));

  for (int i = 0; i < cols; ++i)
  {
    for (int j = 0; j < rows; ++j)
    {
      random = (float) rand() / (float) RAND_MAX;

      if (random < density)
      {
        grid [i][j] = true;
      }
      else
      {
        grid [i][j] = false;
      }
    }
    cout << endl;
  }
  return grid;
}
