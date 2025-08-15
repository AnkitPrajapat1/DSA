#include<iostream>
#include<stack>
#include<queue>
using namespace std;


void print(queue<int>q)
    {
        cout << "Printitng Queue: ";
        while(!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
void reverseQueueUsingStack(queue<int>&q){
    stack<int>s;
    while(!q.empty()){
        int frontEle=q.front();
        q.pop();
        s.push(frontEle);
      
    }
    
    while(!s.empty()){
        int topEle=s.top();
        s.pop();
        q.push(topEle);
     

    }
}

void reverseQueueUsingRecurssion(queue<int>&q){
    if(q.empty()){
     return;
    }
    int frontEle=q.front();
    q.pop();
    reverseQueueUsingRecurssion(q);
    q.push(frontEle);
}
int main(){

    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    print(q);
    reverseQueueUsingRecurssion(q);
    print(q);
    return 0;
}