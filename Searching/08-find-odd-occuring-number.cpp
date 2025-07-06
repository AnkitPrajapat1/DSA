#include <iostream>
#include <vector>
using namespace std;

int findOddOccuringElement(vector<int> arr)
{
    int n = arr.size();
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (s == e)
        {
            return s;
        }
        if (mid % 2 == 0)
        {
            if (arr[mid] == arr[mid + 1])
            {
                s = mid + 2;
            }
            else
            {
                e = mid;
            }
        }
        else
        {
            if (arr[mid] == arr[mid - 1])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}
int main()
{
    vector<int> arr = {2, 2, 3, 3, 4, 4, 6, 6, 7, 7, 9};
    int result = findOddOccuringElement(arr);
    if (result != -1)
        cout << "element is " << arr[result] << endl;
    else
        cout << "No odd acuring element" << endl;
    return 0;
}