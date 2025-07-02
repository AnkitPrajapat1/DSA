#include <iostream>
#include <utility>
using namespace std;

void sortZeroOne(int arr[],int size){
    // cout zero's and one's
    int zeros=0,ones=0;
    for(int i=0;i<size;i++){
        if(arr[i]==0) zeros++;
        if(arr[i]==1) ones++;
    }
    int index=0;
    while(zeros--){
        arr[index]=0;
        index++;
    }
    while(ones--){
        arr[index]=1;
        index++;
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

void sortTwoPointer(int arr[],int size){
    int i=0,j=1;
    while(j<size){
        if(arr[j]<arr[i]){
        swap(arr[i],arr[j]);
        i++;
        // cout<<i<<endl;
        }
        j++;
    }
  for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={1,0,0,1,1,0,1,0,1,1,0,0,0};  
    int size= 13;
    sortTwoPointer(arr,size);
    return 0;
}