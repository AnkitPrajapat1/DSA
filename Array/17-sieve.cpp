#include<iostream>
#include<vector>
using namespace std;


vector<bool>prime(int n){
vector<bool>sieve(n+1,true);
sieve[0]=sieve[1]=false;

for(int i=2;i*i<=n;i++){ // optimization 2  
    if(sieve[i]==true){
    //   int j=i*2;
         int j=i*i; //Optimization 1 :first unmarked number would be i*i, as others have been marked by 2 to (i-1)
      while(j<=n){
        sieve[j]=false;
        j+=i;
      }
    }
}
return sieve;
}

int main(){
    cout<<"Enter a number: ";
    int n;
    cin>>n;

    vector<bool>result=prime(n);
    for(int i=0;i<n;i++){
        if(result[i]){

            cout<<i<<" ";
        }
    }
    return 0;
}