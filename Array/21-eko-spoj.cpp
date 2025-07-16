#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int solve(int arr[], int n, int m, int mid)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= mid)
        {
            sum += arr[i] - mid;
        }
    }
    if (sum > m)
        return 1;
    else
        return 0;
}
int binary(int arr[], int n, int m)
{
    int start = 0;
    int maxi = 0;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        maxi = max(arr[i], maxi);
    }
    int end = maxi;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (solve(arr, n, m, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return mid;
}
int main()
{
    int arr[5] = {4, 42, 40, 26, 46};
    int n = 5;
    int m = 20;

    cout << binary(arr, n, m) << endl;
    return 0;
}