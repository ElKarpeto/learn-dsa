#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *next;
    Node *previous;
    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
        previous = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class doublyLinkedList
{
    Node *head;
    doublyLinkedList()
    {
        head = NULL;
    }
    doublyLinkedList(Node *n)
    {
        head = n;
    }

    Node *nodeExist(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;

        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    void appendNode(Node *n)
    {
        if (nodeExist(n->key) != NULL)
        {
            cout << "node dengan key " << n->key << " sudah terisi" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "node telah ter append" << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->previous = ptr;
            }
        }
    }

    void prependNode(Node *n)
    {
        if (head == NULL)
        {
            head = n;
            cout << "node telah berhasil di prepend" << endl;
        }
        else
        {
            Node *ptr = head;
            n->next = ptr;
            ptr = n;
            ptr->previous = n;
            cout << "node telah berhasil di prepend" << endl;
        }
    }

    void insertNode(int k, Node *n)
    {
        Node *ptr = nodeExist(k);
        if (ptr == NULL)
        {
            cout << "node dengan key " << k << " tidak ada" << endl;
        }
        else
        {
            Node *after = ptr->next;
            ptr->next = n;
            n->previous = ptr;
            n->next = after;
            after->previous = n;
            cout << "telah berhasi meng-insert node setelah key " << k << endl;
        }
    }

    void deleteNode(int k)
    {
        if (head == NULL)
        {
            cout << "linked list kosong" << endl;
        }
        else if (head != NULL)
        {
            Node *temp = NULL;
            Node *ptr = head;
            Node *current = head->next;
            while (current != NULL)
            {
                if (current->key == k)
                {
                    temp = current;
                    current = NULL;
                }
                else
                {
                    ptr = ptr->next;
                    current = current->next;
                }
            }

            if (temp != NULL)
            {
                ptr->next = temp->next;
                temp->previous = ptr;
                cout << "node dengan key " << k << " telah di delete" << endl;
            }
            else
            {
                cout << "node dengan key " << k << " tidak ada" << endl;
            }
        }
    }

    void updateNode(int k, int d)
    {
        Node *ptr = nodeExist(k);
        if (ptr == NULL)
        {
            cout << "node dengan key " << k << " tidak ada" << endl;
        }
        else
        {
            ptr->data = d;
            cout << " data node dengan key " << k << " telah di update, data : " << d << endl;
        }
    }

    void displayNode()
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << "Linked List : " << endl;
            cout << ptr->key << " : " << ptr->data << " <--> ";

            ptr = ptr->next;
        }
    }
};

int main()
{
}