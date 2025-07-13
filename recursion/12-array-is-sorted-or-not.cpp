#include <iostream>
#include <limits.h>
using namespace std;

bool sortedOrNot(int arr[], int size, int index)
{
    if (index >= size)
    {
        return true;
    }
    if (arr[index - 1] < arr[index])
    {
        return sortedOrNot(arr, size, index + 1);
    }
    else
    {
        return false;
    }

    return true;
}
int main()
{

    int arr[6] = {1, 3, 5, 14, 9, 11};
    int size = 6;
    int index = 1;
    int result = sortedOrNot(arr, size, index);
    if (result)
        cout << "Sorted" << endl;
    else
        cout << "not Sorted" << endl;
    return 0;
}