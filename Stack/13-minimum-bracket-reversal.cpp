#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int minimumBracketReversal(string str)
{
    int n = str.length();
    if (n & 1)
    {
        return -1;
    }

    stack<char> st;

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '}' && !st.empty())
        {
            if (st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push(str[i]);
            }
        }
        else
        {
            st.push(str[i]);
        }
    }

    int remain = st.size();
    int a = 0;
    while (!st.empty())
    {
        if (st.top() == '{')
        {
            a++;
        }
        st.pop();
    }

    return (remain/2) +(a%2);
}

int main()
{
    string str = "{{{{{{}{{{";
    cout << minimumBracketReversal(str) << endl;
    return 0;
}