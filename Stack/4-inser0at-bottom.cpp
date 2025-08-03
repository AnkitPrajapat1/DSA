#include <iostream>
#include <stack>
using namespace std;


void insertAtBottom(stack<int> &st, int data)
{

    if (st.empty())
    {
        st.push(data);
        return;
    }
    int temp = st.top();
    st.pop();
    insertAtBottom(st, data);
    st.push(temp);
}
int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    // st.push(50);
    // st.push(60);
    cout<<st.size();
    insertAtBottom(st, 400);
    cout<<st.size();
    return 0;
}