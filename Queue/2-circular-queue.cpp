#include <iostream>
using namespace std;

class Cqueue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Cqueue(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push(int val)
    {
        // check full
        if ((front == 0 && rear == size - 1) || (rear == front - 1))
        {
            cout << "Queue OverFlow" << endl;
            return;
        }
        else if (front == -1 && rear == -1)
        {
            // empty case
            front++;
            rear++;
            arr[rear] = val;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = val;
        }
        else
        {
            // normal case
            rear++;
            arr[rear] = val;
        }
    }

    void pop()
    {
        // underflow
        if (front == -1 && rear == -1)
        {
            cout << "Queue UnderFlow" << endl;
            return;
        }
        else if (front == rear)
        {
            // empty case -> single element
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            arr[front] = -1;
            front = 0;
        }
        else
        {
            // normal case
            arr[front] = -1;
            front++;
        }
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }
    int getSize()
    {
        return rear - front + 1;
    }
    int getFront()
    {
        if (front == -1)
        {
            cout << "No element in queue, cannot give front element" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    void print()
    {
        cout << "Printitng Queue: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Cqueue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.print();
    cout << q.getSize() << endl;
    q.pop();
    q.pop();
    q.pop();
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);

    q.print();
    // cout << q.getFront() << endl;
    return 0;
}