#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top;
    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    void push(int data)
    {
        if (top == size - 1)
            cout << "Stack is full";
        else
        {
            top++;
            arr[top] = data;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    void pop()
    {
        if (isEmpty())
            cout << "Stack is empty";
        else
            top--;
    }
    int getTop()
    {
        if (isEmpty()){
            cout << "Stack is empty";
            return -1;}
        else
            return arr[top];
    }
    int getSize()
    {
        return top + 1;
    }
};
int main()
{
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout<<st.getTop()<<endl;
    st.pop();
    cout<<st.getTop()<<endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();


    return 0;
}