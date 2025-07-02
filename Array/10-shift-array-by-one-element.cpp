#include <iostream>
using namespace std;

// void shiftArray(int arr[],int size){
// int last=arr[size-1];
// for(int i=size-1;i>=0;i--){
//   arr[i]=arr[i-1];
// }
// arr[0]=last;
// for(int i=0;i<size;i++){
//     cout<<arr[i]<<" ";
// }
// }

void shiftArray(int arr[],int size,int stepSize){
int n=stepSize;    
int tempArr[stepSize];
int i=0;
int temp=stepSize;
while(temp--){
    tempArr[i]=arr[size-1-i];  //5 4 3
    // cout<<tempArr[i]<<" ";
    i++;
    
}

int last=arr[size-1];
for(int i=size-1;i>=stepSize;i--){
  arr[i]=arr[i-stepSize];
//   cout<<arr[i]<<" ";
}

for(int i=0;i<stepSize;i++){
  arr[i]=tempArr[stepSize-1-i];
  
}


for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
}
}
int main(){
    int arr[]={10,20,30,40,50,60};
    int size=6;
    int stepSize=3;
    shiftArray(arr,size,stepSize);
    return 0;
}