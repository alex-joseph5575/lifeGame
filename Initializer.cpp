#include "Initializer.h"
#include <iostream>

using namespace std;

Initializer::Initializer()
{

}

Initializer::~Initializer()
{

}

void Initializer::createWorld()
{
  cout << "Would you like to provide a map file?" << endl;
  while (true)
  {
    cout << "1) Yes" << endl;
    cout << "2) No" << endl;
    cout << "3) Exit" << endl;
    getline(cin, input);
    cout << "" << endl;

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

  if (map == true)
  {
    //createMap();
  }

  else
  {
    //randomMap();
  }
}

void Initializer::createMap()
{
  cout << "Please enter the file path of your map." << endl;
  while (true)
  {
    readline(cin, input);
    cout << "" << endl;
  }
}
