#include <iostream>
#include <vector>
using namespace std;

void printDigit(int n)
{
    if (n == 0)
    {
        return;
    }
    int digit = n % 10;

    printDigit(n / 10);
    cout << digit << " ";
}

void printNumber(vector<int> &v, int &ans, int size, int index)
{
    if (index >= size)
    {
        return;
    }
    ans = ans * 10 + v[index];
    return printNumber(v, ans, size, index + 1);
}
int main()
{

    int n = 5537;
    printDigit(n);

    vector<int> v = {2, 6, 8, 4};
    int ans = 0;
    int index = 0;
    int size = v.size();
    printNumber(v, ans, size, index);
    cout << ans << " ";
    return 0;
}