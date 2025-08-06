#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void nextSmallerElement(int *arr,int &size,vector<int>&ans){
    stack<int>st;
    st.push(-1);
    for(int i=size-1;i>=0;i--){
        int currElement=arr[i];
        while(st.top()>=currElement){
            st.pop();
        }
        ans[i]=st.top();
        st.push(currElement);
    }
}
void previousSmallerElement(int *arr,int &size,vector<int>&ans){
    stack<int>st;
    st.push(-1);
    for(int i=0;i<size;i++){
        int currElement=arr[i];
        while(st.top()>=currElement){
            st.pop();
        }
        ans[i]=st.top();
        st.push(currElement);
    }
}
int main(){
    int arr[5]={8,4,6,2,3};
    int size=5;
    vector<int>ans(size);
    // nextSmallerElement(arr,size,ans);
    previousSmallerElement(arr,size,ans);
    for(auto element : ans){
        cout<<element<<" ";
    }
    cout<<endl;
    return 0;
}