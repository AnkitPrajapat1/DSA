#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &arr, int size)
{
    int j = 1;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            arr[j] = arr[i];
            j++;
        }
    }
    return j;
}

void print(vector<int> &arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{

    vector<int> arr{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int size = arr.size();
    int newSize = removeDuplicates(arr, size);
    print(arr, newSize);
    return 0;
}