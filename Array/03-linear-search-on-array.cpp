#include <iostream>
using namespace std;

int main(){
    int arr[5]={20,30,56,89,31};
    int key=56;
    int flag=0;
    for(int i=0;i<5;i++){
        if(arr[i]==key){
            flag=1;
        }    
    }
    if(flag==1) cout<<"Element found";
    else cout<<"Element not found";
    return 0;
}