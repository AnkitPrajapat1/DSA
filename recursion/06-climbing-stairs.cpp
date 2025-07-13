//we can clibe 1 or 2 stair one at a time find total numbers of way to climb stairs

#include<iostream>
using namespace std;

int climb(int n){
    if(n==0 || n==1){
        return 1;
    }
    return climb(n-1) + climb(n-2);
}
int main(){

    int stair=3;
    int result=climb(stair);
    cout<<"Ans is: "<<result;
    return 0;
}

    