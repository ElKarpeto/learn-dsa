#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    int key;
    Node *next;
    Node() // default parameter
    {
        data = 0;
        key = 0;
        next = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class singlyLinkedlist
{
public:
    Node *head;
    singlyLinkedlist()
    { // default parameter
        head = NULL;
    }
    singlyLinkedlist(Node *n)
    {             // pass by pointer
        head = n; // kita mempointing n
    }
    // cek jika node ada
    Node *nodeExist(int k)
    {
        Node *temp = NULL;
        Node *ptr = head; // ptr mem-point head

        while (ptr != NULL)
        {
            if (ptr->key == k) // jika head.key == k
            {
                temp = ptr;
            }
            ptr = ptr->next; // bila head.key != k, maka akan next
        }
        return temp;
    }
    // append node
    void appendNode(Node *n)
    {
        if (nodeExist(n->key) != NULL) // cek apakah key yang kita masukan telah di isi suatu nilai
        {
            cout << "node dengan key " << n->key << " telah terisi" << endl;
        }
        else
        {
            if (head == NULL) // bila head == NULL, maka node yang kita append akan menjadi head
            {
                head = n;
                cout << "Node telah berhasil di append" << endl;
            }
            else
            {
                // block code ini untuk trafersing linkedlist nya
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                // karena n sudah di pass by point, maka kita tidak perlu memasukan &n
                ptr->next = n;
                cout << "Node telah berhasil di append" << endl;
            }
        }
    }
    // prepend node
    void prependNode(Node *n)
    {
        if (head == NULL)
        {
            head = n;
            cout << "Node telah berhasil di prepend" << endl;
        }
        else
        {
            n->next = head;
            head = n;
            cout << "Node telah berhasil di prepend" << endl;
        }
    }
    // insert node after a key N in a list
    void insert(int k, Node *n)
    {
        Node *ptr = nodeExist(k);
        if (ptr == NULL)
        {
            cout << "tidak ada node dengan key " << k << endl;
        }
        else
        {
            if (nodeExist(n->key) != NULL)
            {
                cout << "node dengan key " << n->key << " telah terisi" << endl;
            }
            else
            {
                n->next = ptr->next;
                ptr->next = n;
                cout << "node telah berhasil di insert setelah key " << k << endl;
            }
        }
    }
    // delete a node with k key
    void deletionNode(int k)
    {
        if (head == NULL)
        {
            cout << "linked list kosong" << endl;
        }
        else if (head != NULL)
        {
            if (head->key == k)
            {
                head = head->next; // bila node yang kita ingin delete adalah head
                cout << "node telah berhasil di delete (sebagai head)" << endl;
            }
            else
            {
                Node *temp = NULL;
                Node *preptr = head;
                Node *currentptr = head->next;
                while (currentptr != NULL)
                {
                    if (currentptr->key == k)
                    {
                        temp = currentptr; // bila node yang kita ingin delete adalah node setelah head
                        currentptr = NULL;
                    }
                    else
                    {
                        preptr = preptr->next;         // track node k
                        currentptr = currentptr->next; // track node k + 1
                    }
                }
                if (temp != NULL)
                {
                    preptr->next = temp->next;
                    cout << "node dengan key " << k << " telah berhasil di delete" << endl;
                }
                else
                {
                    cout << "node dengan key " << k << " tidak ada" << endl;
                }
            }
        }
    }
    // update data for node k key
    void updateNode(int k, int d)
    {
        Node *ptr = nodeExist(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "node dengan key " << k << " telah terupdate dengan data : " << d << endl;
        }
        else
        {
            cout << "node dengan key " << k << " tidak ada" << endl;
        }
    }
    // display all node in linked list
    void displayAllNode()
    {
        if (head == NULL)
        {
            cout << "linked list kosong" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << "Linked List : " << endl;
                cout << temp->key << " : " << temp->data << " --> ";
                temp = temp->next;
            }
        }
    }
};

int main()
{
    Node n1, n2;
    n1 = Node(1, 32);
    n2 = Node(2, 54);
}