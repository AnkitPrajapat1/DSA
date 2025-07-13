#include <iostream>
#include <limits.h>
using namespace std;

int findMin(int arr[], int size, int &mini, int index)
{
    if (index >= size)
    {
        return mini;
    }
    if (arr[index] < mini)
    {
        mini = arr[index];
    }

    return findMin(arr, size, mini, index + 1);
}
int main()
{

    int arr[6] = {2, 6, 8, 4, 9, 1};
    int size = 6;
    int mini = INT_MAX;
    int result = findMin(arr, size, mini, 0);
    cout << "Ans is: " << result;
    return 0;
}