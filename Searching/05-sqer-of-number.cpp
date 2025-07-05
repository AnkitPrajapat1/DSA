#include <iostream>
#include <vector>
using namespace std;

int mySqrt(int x)
{
    int start = 0;
    int end = x;
    int ans = 0;
    long int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (mid * mid == x)
        {
            ans = mid;
            return ans;
        }
        else if (mid * mid < x)
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
    return ans;
}

int main()
{
    int result = mySqrt(89);
    cout << result;
    return 0;
}