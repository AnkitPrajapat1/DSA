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
void reverseKElement(queue<int>&q,int k){
    int n=q.size();
    stack<int>s;
    for(int i=0;i<k;i++){
        int frontEle=q.front();
        q.pop();
        s.push(frontEle);
    }
    while(!s.empty()){
        int topEle=s.top();
        s.pop();
        q.push(topEle);
    }
    for(int i=0;i<(n-k);i++){
      int frontEle=q.front();
      q.pop();
      q.push(frontEle);
    }
}


int main(){
    int k=2;
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    print(q);
    reverseKElement(q,k);
    print(q);
    return 0;
}