// Given a fence with n posts and k colours, find out the number of ways of painting the fence so that not more than two consecutive posts have the same colours.
// Input: n = 3, k = 2 
// Output: 6
// Explanation: Let the 2 colours be 'R' and 'B'. We have following possible combinations:
// 1. RRB
// 2. RBR
// 3. RBB
// 4. BRR
// 5. BRB
// 6. BBR


#include<iostream>
using namespace std;


int getPaintway(int n, int k){
if(n==1) return k;
if(n==2) return k*(k-1);
int ans=(k-1)*(getPaintway(n-1,k)+getPaintway(n-2,k));
return ans;
}
int main(){
    int n=3;
    int k=3;
    cout<<getPaintway(n,k);
    return 0;

}