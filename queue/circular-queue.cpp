#include <iostream>
using namespace std;

class circularQueue
{
private:
    int arr[5];
    int front;
    int rear;

public:
    circularQueue()
    {
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
        front = -1;
        rear = -1;
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if ((rear + 1) % 5 == front)
        {
            return true;
        }
        else
            return false;
    }
    int enqueue(int val)
    {
        if (isFull() == true)
        {
            cout << "your Circular Queue is full" << endl;
            return 0;
        }
        else if (isEmpty() == true)
        {
            rear = 0;
            front = 0;
        }
        else
        {
            rear = (rear + 1) % 5;
        }
        arr[rear] = val;
    }
    int dequeue()
    {
        int temp;
        if (isEmpty() == true)
        {
            return 0;
        }
        else if (rear == front)
        {
            temp = arr[front];
            front = -1;
            rear = -1;
        }
        else
        {
            temp = arr[front];
            front = (front + 1) % 5;
        }
        return temp;
    }
    int count()
    {
        return (rear - front + 1);
    }
};

int main()
{
    circularQueue cq1;
    cq1.enqueue(34);
    cq1.enqueue(9);
    cq1.enqueue(65);

    cout << cq1.dequeue() << endl;
    cout << cq1.dequeue() << endl;
    cout << cq1.dequeue() << endl;
    cout << cq1.dequeue() << endl;
}