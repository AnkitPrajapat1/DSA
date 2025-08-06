#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;

class minStack
{
    stack<int> s;
    int mini = INT_MAX;

public:
    void push(int data)
    {
        if (s.empty())
        {
            s.push(data);
            mini = data;
        }
        else
        {
            if (data < mini)
            {
                s.push(2 * data - mini);
                mini = data;
            }
            else
            {
                s.push(data);
            }
        }
    }

    int pop()
    {
        if (s.empty())
        {
            return -1;
        }
        int curr = s.top();
        s.pop();
        if (curr > mini)
        {
            return curr;
        }
        else
        {
            int prevMin = mini;
            int val = 2 * mini - curr;
            mini = val;
            return prevMin;
        }
    }
    int top()
    {
        if (s.empty())
        {
            return -1;
        }
        int curr = s.top();
        if (curr < mini)
        {
            return mini;
        }
        else
        {
            return curr;
        }
    }
    bool isEmpty()
    {
        return s.empty();
    }
    int getMin()
    {
        if (s.empty())
        {
            return -1;
        }
        return mini;
    }
};
int main()
{
    minStack ms;
    ms.push(5);
    ms.push(3);
    cout << ms.getMin() << endl;
    ms.push(7);
    ms.push(2);
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.getMin() << endl;
    return 0;
}