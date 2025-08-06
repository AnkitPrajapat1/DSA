#include <iostream>
#include <stack>
using namespace std;

bool check(string str)
{
    stack<char> st;

    for (auto ch : str)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            int top = st.top();
            if (st.empty())
                return false;
            if (ch == '(' && ch != top || ch == '[' && ch != top || ch == '{' && ch != top)
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }
    return st.empty();
}
int main()
{
    string str = "{()[]{}}";
    if (check(str))
    {
        cout << "Valid";
    }
    else
    {
        cout << "Invalid";
    }
    return 0;
}