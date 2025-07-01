#include <iostream>
using namespace std;

int main(){
    bool arr[]={1,0,1,0,1,0,0,0,1,0,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    int zero=0;
    int one=0;
    for(int i=0;i<size;i++){
        if(arr[i]==1) one++;
        else zero++;
    }
    cout<<"Count of one's is "<<one <<endl << "Count of zero's is "<<zero;
    return 0;
}