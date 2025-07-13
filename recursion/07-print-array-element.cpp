#include<iostream>
using namespace std;

void printArray(int arr[],int size){
    if(size==0){
        return;
    }
    printArray(arr,size-1);
    cout<<arr[size-1]<<" ";
}
int main(){

    int arr[5]={1,2,3,4,5};
    int size=5;
    printArray(arr,size);

    return 0;
}