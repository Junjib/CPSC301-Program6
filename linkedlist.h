//begin linkedlist.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

using namespace std;

struct node
{
    int data;
    node * next;
};

class linkedlist
{
private:
    node * head;
    node * headBackup;
    int count(); // RECURSIVE
    int sum(); // RECURSIVE
    void printList(node* head);
    void insert(node* prev, int num);
    void deleteNode(node* head);
    void resetHead(node* headBackup);

public:
    linkedlist();
    ~linkedlist(); // RECURSIVE
    void addToFront(int n);
    double average(); // uses sum and count functions
    void writeInorder(string & file);
    void writeReversed(string & file);
};
#endif // end linkedlist.h
