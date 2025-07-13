#include <iostream>
#include <limits.h>
using namespace std;

int binarySearch(int arr[], int size, int s, int e, int target)
{
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            // e=mid-1;
            return binarySearch(arr, size, s, mid - 1, target);
        }
        else
        {
            // s=mid+1;
            return binarySearch(arr, size, mid + 1, e, target);
        }
    }
    return -1;
}
int main()
{

    int arr[8] = {1, 3, 5, 7, 9, 11, 12, 14};
    int size = 8;
    int target = 11;
    int s = 0;
    int e = size - 1;
    int result = binarySearch(arr, size, s, e, target);
    if (result != -1)
        cout << "Found at index : " << result << endl;
    else
        cout << "Not found";
    return 0;
}