#include <iostream>
using namespace std;
int dearrangements(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    int ans = (n - 1) * (dearrangements(n - 1) + dearrangements(n - 2));
    return ans;
}
int main()
{
    int n = 4;
    cout << dearrangements(n);
}