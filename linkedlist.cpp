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

  if(head == nullptr)
  {
    newNode->data = n;
    head = newNode;
    printList(head);
    return;
  }

  node *prev = nullptr;
  for(prev = head; prev != nullptr; prev = prev->next)
  {
    if(n < head->data)
    {
      newNode->data = n;
      newNode->next = head;
      head = newNode;
      printList(head);
      break;
    }
    else if(prev->next == nullptr)
    {
      newNode->data = n;
      prev->next = newNode;
      printList(head);
      break;
    }
    else if(n >= prev->data && prev->next != nullptr && n < prev->next->data)
    {
      insert(prev, n);
      printList(head);
      break;
    }
  }
}

double linkedlist::average()
{
    // uses sum and count functions
    int size = 0;
    int sumOfList = 0;
    size = count();
    sumOfList = sum();
    cout << size << endl;
    //cout << sumOfList << endl;
    return 0.0;
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
      head = head->next;
      return (listSum + sum());
    }
}

void linkedlist::writeInorder(string & file)
{

}

void linkedlist::writeReversed(string & file)
{
    // RECURSIVE
}

void linkedlist::printList(node* &head)
{
  for(node *testA = head; testA != nullptr; testA = testA->next)
  {
    cout << testA->data << " ";
  }
  cout << endl;
}

void linkedlist::insert(node* &prev, int num)
{
  node *newNode = new node;
  newNode->data = num;
  newNode->next = prev->next;
  prev->next = newNode;
  return;
}
