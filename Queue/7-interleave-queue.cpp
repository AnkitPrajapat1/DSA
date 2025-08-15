#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void print(queue<int> first)
{
    cout << "Printitng queue: ";
    while (!first.empty())
    {
        cout << first.front() << " ";
        first.pop();
    }
    cout << endl;
}
void interleavedQueue(queue<int> &first)
{
    int n = first.size();
    int it = n / 2;
    if (n & 1)
    {
        it = (n / 2) + 1;
    }
    queue<int> second;
    stack<int> s;
    for (int i = 0; i < it; i++)
    {
        int frontEle = first.front();
        first.pop();
        second.push(frontEle);
    }
    int count = 0;
    for (int i = 0; i < it; i++)
    {
        int temp = second.front();
        second.pop();
        first.push(temp);
        count++;
        if (count < it)
        {

            int temp2 = first.front();
            first.pop();
            first.push(temp2);
        }
    }
}

int main()
{
    int k = 2;
    queue<int> first;
    first.push(10);
    first.push(20);
    first.push(30);
    first.push(40);
    first.push(50);
    first.push(60);
    first.push(70);

    print(first);
    interleavedQueue(first);
    print(first);
    return 0;
}