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
    //printList(head);
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
      //printList(head);
      return;
    }
    else if(prev->next == nullptr)
    {
      newNode->data = n;
      prev->next = newNode;
      //printList(head);
      return;
    }
    else if(n >= prev->data && prev->next != nullptr && n < prev->next->data)
    {
      insert(prev, n);
      //printList(head);
      return;
    }
  }
}

double linkedlist::average()
{
    // uses sum and count functions
    //printList(head);
    int size = count();
    int sumOfList = sum();
    cout << size << endl;
    cout << sumOfList << endl;
    return 0.0;
}

int linkedlist::sum()
{
    // RECURSIVE
    if(head == nullptr)
    {
      return 0;
    }
    else
    {
      head = head->next;
      return (head->data + sum());
    }
}

void linkedlist::writeInorder(string & file)
{
  ofstream writeData;
  node *write = head;
  writeData.open(file, ofstream::app);
  while(write != nullptr)
  {
    writeData << write->data << " ";
    write = write->next;
  }
  writeData.close();
}

void linkedlist::writeReversed(string & file)
{
    // RECURSIVE
    ofstream writeData;
    writeData.open(file, ofstream::app);
    if(head->next == nullptr)
    {
      writeData << endl << head->data << " ";
      writeData.close();
      return;
    }
    else
    {
      writeData << head->data << " ";
      head = head->next;
      writeReversed(file);
      return;
    }
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
