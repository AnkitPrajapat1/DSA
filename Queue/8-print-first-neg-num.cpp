#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void solve(vector<int> &v, int n, int k)
{

    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        int element = v[i];
        if (element < 0)
        {
            dq.push_back(i);
        }
    }

    for (int i = k; i <= n; i++)
    {
        if (dq.empty())
        {
            cout << "0 " << endl;
        }
        else
        {
            cout << v[dq.front()] << " ";
        }

        // removal
        if (i - dq.front() >= k)
        {
            dq.pop_front();
        }
        // addition
        if (v[i] < 0)
        {
            dq.push_back(i);
        }
    }
}
int main()
{

    vector<int> v = {2, -5, 4, -1, -2, 0, 5, -6};
    int size = 8;
    int k = 3;
    solve(v, size, k);
    return 0;
}