#include <iostream>
using namespace std;

class queue
{
private:
    int arr[5];
    int front;
    int rear;

public:
    queue()
    {
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
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
        if (rear == 5 - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue(int val)
    {
        if (isFull() == true)
        {
            cout << "your queue is full" << endl;
        }
        else if (isEmpty() == true)
        {
            rear = 0;
            front = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = val;
    }
    int dequeue()
    {
        int temp = 0;
        if (isEmpty() == true)
        {
            return 0;
        }
        else if (front == rear)
        {
            temp = arr[front];
        }
        else
        {
            temp = arr[front];
            arr[front] = 0;
            front++;
        }
        return temp;
    }
    int count()
    {
        return (rear - front + 1);
    }
    void display()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    queue q1;
    q1.enqueue(32);
    q1.enqueue(1);
    q1.enqueue(3);

    q1.display();
    return 0;
}