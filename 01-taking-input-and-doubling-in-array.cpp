#include <iostream>
using namespace std;

int main(){
    int arr[10];
    int sum;
    cout<<"Enter Values in Array";
    for(int i=0;i<10;i++){
        cin>>arr[i];
    }
    for(int i=0;i<10;i++){
        arr[i]=2*arr[i];
    }
    cout<<"Doubled Array";
    for(int i=0;i<10;i++){
       cout<<arr[i]<<" ";
    }
    
    return 0;
}