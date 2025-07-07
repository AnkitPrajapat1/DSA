#include<iostream>
#include<vector>
#include<utility>
using namespace std;

void bubbleSort(vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]<arr[j+1]){
                swap(arr[j],arr[j+1]);

            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    vector<int>arr={7,5,9,2,4,6,1,2};
    bubbleSort(arr);
    return 0;
}