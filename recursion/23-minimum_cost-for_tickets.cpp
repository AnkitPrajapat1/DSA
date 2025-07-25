#include<iostream>
#include<vector>        
#include<algorithm>
using namespace std;

    int solve(int n, vector<int>& days, vector<int>& costs, int index, vector<int>& dp) {
        if (index >= n)
            return 0;
        if (dp[index] != -1)
            return dp[index];
        int option1 = costs[0] + solve(n, days, costs, index + 1, dp);
        int i;
        // 7 days
        for (int i = index; i < n && (days[i] < days[index] + 7); i++)
            ;
        int option2 = costs[1] + solve(n, days, costs, i, dp);

        // 30 days
        for (int i = index; i < n && (days[i] < days[index] + 30); i++)
            ;
        int option3 = costs[2] + solve(n, days, costs, i, dp);

        dp[index] = min(option1, min(option2, option3));
        return dp[index];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int index=0;
        vector<int> dp(n + 1, -1);
        return solve(n, days, costs, index, dp);
    }

    int main(){
        vector<int>days={1,4,6,7,8,20};
        vector<int>costs={2,7,15};
        cout<<mincostTickets(days,costs);
        return 0;
    }