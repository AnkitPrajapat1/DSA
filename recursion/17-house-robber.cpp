// House robber
//  given an array of houses. we can only rob adjacent houses.we have to return the maximum amount which can be rob.

#include <iostream>
#include <limits.h>
using namespace std;

int solve(int nums[], int size, int index)
{
    if (index >= size)
    {
        return 0;
    }

    int option1 = nums[index] + solve(nums, size, index + 2);
    int option2 = 0 + solve(nums, size, index + 1);
    int finalAns = max(option1, option2);
    return finalAns;
}
int main()
{

    int arr[6] = {2, 6, 8, 4, 9, 1};
    int size = 6;
    int index = 0;
    int result = solve(arr, size, index);
    cout << "Ans is: " << result;
    return 0;
}