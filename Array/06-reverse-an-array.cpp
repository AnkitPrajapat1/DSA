#include <iostream>
using namespace std;

void swap(int arr[],int a,int b){
   int temp; 
   temp=arr[a];
   arr[a]=arr[b];
   arr[b]=temp;

}
int main(){

    int arr[]={5,9,30,50,60,6,80};
    int size=sizeof(arr)/sizeof(arr[0]);
    int left=0;
    int right=size-1;

    // reverse an array

    // for(int i=0;i<size;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<size/2;i++){
    //     swap(arr,left,right);
    //     left++;
    //     right--;
    // }
    // for(int i=0;i<size;i++){
    //     cout<<arr[i]<<" ";
    // }

    // extreme print
    while(left<=right)
    {
        cout<<arr[left]<<" ";
        if(left<right)
        cout<<arr[right]<<" ";
        left++,right--;
        
    }
   


    return 0;
}