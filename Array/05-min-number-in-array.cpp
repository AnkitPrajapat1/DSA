#include <iostream>
#include <limits.h>
using namespace std;

int main(){
    int arr[]={9,8,3,34,87};
    int size=5;
    int min=INT_MAX;
    for(int i=0;i<size;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    cout<<"Min number is: "<<min;
    return 0;
}