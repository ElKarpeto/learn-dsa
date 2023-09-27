#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    int key;
    Node *next;
    Node()
    {
        data = 0;
        key = 0;
        next = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
        next = NULL;
    }
};

int main()
{
    Node n1, n2;
    n1 = Node(1, 20);
    n2 = Node(2, 45);
}