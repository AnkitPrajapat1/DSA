#include <iostream>
using namespace std;

int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + sum(n - 1);
}
int main()
{

    int n = 10;
    int result = sum(n);
    cout << "Ans is: " << result;
    return 0;
}