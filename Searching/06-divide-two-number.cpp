#include<iostream>
#include<vector>
using namespace std;

int divide(int divident,int divisor){
    int s=0;
    int e=divident;
    int mid= s+(e-s)/2;
    int result;
    while(s<=e){
        if(mid*divisor==divident){
            return mid;
        }
        else if(mid*divisor<divident){
              result=mid;
              s=mid+1;
        }
        else e=mid-1;
        mid= s+(e-s)/2;
    }
    return result;
}
int main(){

    int divident=45;
    int divisor=-10;
    int result=divide(abs(divident),abs(divisor));
    if((divident<0 && divisor>0)||(divident>0 && divisor<0)){
        cout<<"Ans is -"<<result<<endl;
    }
    else cout<<"Ans is "<<result<<endl;
    return 0;

}