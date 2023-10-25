#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *next = NULL;
    Node *circular;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
        circular = NULL;
    }

    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class circularLinkedlist
{
    Node *head;
};

int main()
{
}