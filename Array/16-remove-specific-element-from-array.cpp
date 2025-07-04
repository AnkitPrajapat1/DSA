#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> &arr, int size, int val)
{
    int index = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != val)
        {
            arr[index] = arr[i];
            index++;
        }
    }
    return index;
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

    vector<int> arr{0, 1, 2, 2, 3, 7, 2, 9, 5, 4};
    int size = arr.size();
    int val = 2;
    int newSize = removeElement(arr, size, val);
    print(arr, newSize);
    return 0;
}