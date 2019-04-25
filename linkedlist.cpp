#include "linkedlist.h"

linkedlist::linkedlist()
{
  head = nullptr;
}

linkedlist::~linkedlist()
{
    // RECURSIVE
}

int linkedlist::count()
{
    // RECURSIVE
    if(head == nullptr)
    {
      return 0;
    }
    else
    {
      head = head->next;
      return 1 + count();
    }
}

void linkedlist::addToFront(int n)
{
  node *newNode = new node;
  node *temp = nullptr;
  if(head == nullptr)
  {
    newNode->data = n;
    head = newNode;
  }
  else
  {
    newNode->data = n;
    if(newNode->data < head->data)
    {
      newNode->next = head;
      head = newNode;
    }
    if(newNode->data > head->data)
    {
      if(head->next == nullptr)
      {
        head->next = newNode;
      }
      else if(newNode->data < head->next->data)
      {
        temp = head->next;
        head->next = newNode;
        newNode->next = temp;
      }
    }
  }
  for(node *test = head; test != nullptr; test = test->next)
  {
    cout << test->data << " ";
  }
  cout << endl;
}

double linkedlist::average()
{
    // uses sum and count functions
}

int linkedlist::sum()
{
    // RECURSIVE
    int listSum = 0;
    if(head == nullptr)
    {
      return listSum;
    }
    else
    {
      return listSum + sum();
      head = head->next;
    }
}

void linkedlist::writeInorder(string & file)
{

}

void linkedlist::writeReversed(string & file)
{
    // RECURSIVE
}
