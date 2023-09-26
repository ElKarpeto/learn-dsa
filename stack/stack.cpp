#include <iostream>
using namespace std;

class stack
{
private:
    int arr[5];
    int top;

public:
    stack() // contruct dari class stack
    {
        top = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty() // untuk cek apakah stack kita kosong
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    bool isFull() // untuk cek apakah stack kita full
    {
        if (top == 4)
            return true;
        else
            return false;
    }
    void push(int val) // untuk memasukan value ke stack
    {
        if (isFull() == true)
        {
            cout << "stack overload" << endl;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }
    int pop() // untuk mengambil nilai dari stack (nilai paling akhir (dalam array))
    {
        if (isEmpty() == true)
        {
            cout << "stack is empty" << endl;
            return 0;
        }
        else
        {
            int pop_value = arr[top];
            arr[top] = 0;
            top--;
            return pop_value;
        }
    }
    int count() // untuk menghitung ada berapa stack yang telah terisi
    {
        return (top + 1);
    }
    int peek(int index) // untuk melihat isi dari stack dengan index tertentu
    {
        if (isEmpty() == true)
        {
            cout << "stack is empty" << endl;
        }
        else if ((index - 1) > top)
        {
            cout << "your peek is overloading" << endl;
        }
        else
        {
            return arr[(index - 1)];
        }
    }
    void change(int val, int index) // untuk mengubah value dari stack yang kita inginkan
    {
        arr[(index - 1)] = val;
        cout << "item change at position " << index << " with value " << val << endl;
    }
    void display() // untuk menampilkan isi stack kita
    {
        for (int i = 4; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    stack s1;
    s1.push(5);
    s1.push(3);
    s1.push(10);
    s1.push(923);
    s1.push(4);
    cout << s1.pop() << endl;
    return 0;
}