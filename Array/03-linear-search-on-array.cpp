#include <iostream>
using namespace std;

bool linearSearch(int arr[],int key,int n){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return true;
        }
    }
    return false;
}
int main(){
    int arr[5]={20,30,56,89,31};
    int key=56;
    int size=5;
    bool flag=0;
    // for(int i=0;i<5;i++){
    //     if(arr[i]==key){
    //         flag=1;
    //     }    
    // }
    // if(flag==1) cout<<"Element found";
    // else cout<<"Element not found";
    // return 0;

    // using function
    flag = linearSearch(arr,40,size);
    if(flag==true) cout<<"Element found";
    else cout<<"Element not found";

}