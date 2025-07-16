#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int solve(int cooks[], int n, int p, int mid)
{
    int minute = 0;
    int paratha=0;
    for (int i = 0; i < n; i++)
    {
       minute=cooks[i];
       int j=2;
       while(minute<=mid){
        paratha++;
        minute = minute + (cooks[i]*j);
        j++;
       }
       if(paratha>=p) return 1;
    }
    return 0;
}
int binary(int cooks[], int n, int p)
{
    int start = 0;
    int ans = -1;

    int end = 1e8;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        cout<<mid<<endl;
        if (solve(cooks, n, p, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return mid;
}
int main()
{
    int cooks[4] = {1, 2, 3,4};
    int n = 4;
    int p = 15;

    cout << binary(cooks, n, p) << endl;
    return 0;
}