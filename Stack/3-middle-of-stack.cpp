#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &st, int &pos, int &ans)
{
    if (pos == 1)
    {
        ans = st.top();
        return;
    }
    int temp = st.top();
    st.pop();
    pos--;
    solve(st, pos, ans);
    st.push(temp);
}
int findMid(stack<int> &st)
{
    int size = st.size();
    if (st.empty())
    {
        return -1;
    }
    int pos = 0;
    // odd
    if (size & 1)
    {
        pos = (size / 2) + 1;
    }
    // even
    else
        pos = size / 2;

    int ans = -1;
    solve(st, pos, ans);
    return ans;
}
int main()
{
    stack<int> st;
    st.push(10);
    // st.push(20);
    // st.push(30);
    // st.push(40);
    // st.push(50);
    // st.push(60);

    cout << findMid(st);
    return 0;
}