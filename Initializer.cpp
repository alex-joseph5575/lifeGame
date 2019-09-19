#include "Initializer.h"
#include <iostream>

using namespace std;

Initializer::Initializer()
{
  map = 0;
}

void Initializer::createWorld()
{
  cout << "Would you like to provide a map file?" << endl;
  while (true)
  {
    cout << "1) Yes" << endl;
    cout << "2) No" << endl;
    cout << "3) Exit" << endl;
    cin >> input;
    cout << "" << endl;

    if (input == "1" || input == "Yes" || input == "YES")
    {
      map = true;
      break;
    }

    else if (input == "2" || input == "No" || input == "NO")
    {
      map = false;
      break;
    }
    else if (input == "3" || input == "Exit" || input == "EXIT")
    {
      cout << "Have a nice day!" << endl;
      exit(0);
    }
    else
    {
      cout << "Invalid input. Please select one of the provided options." << endl;
    }
  }
}
