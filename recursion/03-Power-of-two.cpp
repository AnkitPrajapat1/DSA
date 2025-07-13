#include <iostream>
using namespace std;

int powerOfTwo(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return 2 * powerOfTwo(n - 1);
}
int main()
{

    int n = 10;
    int result = powerOfTwo(n);
    cout << "Ans is: " << result;
    return 0;
}