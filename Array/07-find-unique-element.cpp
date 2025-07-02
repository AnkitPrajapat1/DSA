#include <iostream>
using namespace std;

int findUnique(int arr[],int size){
 int ans=0;
 for(int i=0;i<size;i++){
    ans=ans^arr[i];
 }
 return ans;
}
int main(){
    int arr[]={2,5,7,9,2,6,9,7,5};
    int size=9;
    int finalAns=findUnique(arr,size);
    cout<<"Unique element is: "<<finalAns;
}