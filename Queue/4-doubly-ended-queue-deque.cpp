// #include<iostream>
// #include<deque>
// using namespace std;
// int main()
// {
//     deque<int> q;
//     q.push_back(10);
//     q.push_front(20);
//     q.push_front(30);
//     cout<<"back "<< q.back()<<endl;
//     cout<<"front "<<q.front()<<endl;

//     return 0;
// }

#include <iostream>
using namespace std;

class Deque
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Deque(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void pushBack(int val)
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
    void pushFront(int val)
    {
        // check full
        if (front == 0)
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
            else if (front == 0 && rear != size - 1)
            {
                front = size - 1;
                arr[front] = val;
            }
            else
            {
                // normal case
                front--;
                arr[front] = val;
            }
    }

    void popFront()
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
    void popBack()
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
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
        {
            arr[rear] = -1;
            rear = size - 1;
        }
        else
        {
            // normal case
            arr[rear] = -1;
            rear--;
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
    Deque q(5);
    q.pushBack(10);
    q.pushBack(20);
    q.pushFront(30);
    q.print();
    cout << q.getSize() << endl;
    q.popFront();
    q.print();
    cout << q.getFront() << endl;
    return 0;
}