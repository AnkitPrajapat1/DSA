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

double mySqrtPrecision(int x)
{
    double sqrt = mySqrt(x);
    double stepCount = 0.1;

    int precision = 3;
    double precisionSqrt;
    for (int i = 0; i < precision; i++)
    {
        double j = sqrt;

        while (j * j < x)
        {
            precisionSqrt = j;
            j += stepCount;
        }
        stepCount = stepCount / 10;
        cout << "iteration: " << i << endl;
    }
    return precisionSqrt;
}
int main()
{
    double result = mySqrtPrecision(51);
    cout << result;
    return 0;
}