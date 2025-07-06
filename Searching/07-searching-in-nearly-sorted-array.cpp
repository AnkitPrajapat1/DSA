#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> arr, int size, int target)
{
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] == target)
            return mid;
        else if (mid > 0 && arr[mid - 1] == target)
            return mid - 1;
        else if (mid < size - 1 && arr[mid + 1] == target)
            return mid + 1;
        else if (arr[mid] > target)
        {
            e = mid - 2;
                }
        else
            s = mid + 1;

        mid = s + (e - s) / 2;
    }
    return -1;
}
int main()
{
    vector<int> arr = {3, 2, 4, 6, 5, 8, 7, 9, 11, 10};
    int target = 10;
    int n = arr.size();
    int result = search(arr, n, target);
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "element not found" << endl;
    return 0;
}