#include <iostream>
#include<vector>
#include <limits.h>
using namespace std;

int solve(vector<int>&coins,int amount)
{
    if(amount==0) return 0;
    int mini=INT_MAX;
    int ans=INT_MAX;
    for(int i=0;i<coins.size();i++){
       int coin=coins[i];
       if(coin<=amount){
        int recAns=solve(coins,amount-coin);
        if(recAns!=INT_MAX){
            ans=1+recAns;
        }
        mini=min(mini,ans);
       }
    }
    return mini;
}
int main()
{

    vector<int>coins= {2,5,1};
    int amount=26;
    int size = 6;
    int result = solve(coins,amount);
    
    cout << "Ans is: " << result;
    return 0;
}