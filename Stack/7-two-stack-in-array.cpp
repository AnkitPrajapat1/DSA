#include<iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int top1;
    int top2;
    Stack(int size){
        arr=new int[size];
        this->size=size;
        this->top1=-1;
        this->top2=size;
    }

    void push1(int data){
        if(top2-top1==1){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            top1++;
            arr[top1]=data;
        }
    }
    void push2(int data){
        if(top2-top1==1){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            top2--;
            arr[top2]=data;
        }
    }

    void pop1(){
        if(top1==-1){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            top1--;
        }
    }
    void pop2(){
        if(top1==size){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            top1++;
        }
    }
    void print(){
        cout<<"Top1: "<<top1<<endl;
        cout<<"Top2: "<<top2<<endl;
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Stack st(8);
    st.push1(10);
    st.push1(20);
    st.push1(30);

    st.push2(90);
    st.push2(80);
    st.push2(70);
    st.push2(60);
    st.push2(50);
    st.push2(40);

    st.print();
    return 0;
}
