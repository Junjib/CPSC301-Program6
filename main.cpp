#include <iostream>
#include <string>
#include <fstream>
#include "linkedlist.cpp"

using namespace std;

void readFile(linkedlist & list, string & file)
{
  ifstream readData;
  int number;

  readData.open(file);
  while(readData >> number)
  {
    list.addToFront(number);
  }

  readData.close();
  cout << endl;
}

int main()
{
  string file = "list.txt";
  linkedlist newList;

  readFile(newList, file);

    return 0;
}
