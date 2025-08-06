#include <iostream>
#include <stack>
using namespace std;

bool check(string str)
{
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            int count = 0;
            while (!st.empty() && (st.top() != '('))
            {
                //  cout<<st.top()<<endl;
                //     cout<<"hi"<<endl;
                char temp = st.top();
                // if(temp== '+' || temp== '-' || temp== '*' || temp == '/')
                count++;
                st.pop();
            }

            st.pop();
            if (count == 0)
                return true;
        }
    }
    return false;
}

int main()
{
    string str = "((a+b)*(a+b))";
    if (check(str))
    {
        cout << "redundant";
    }
    else
    {
        cout << "non redundant";
    }
    return 0;
}