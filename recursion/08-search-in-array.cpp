#include <iostream>
using namespace std;

bool search(int arr[], int size, int index, int target)
{
    if (index > size)
    {
        return false;
    }
    if (arr[index] == target)
    {
        return true;
    }
    return search(arr, size, index + 1, target);
}
int main()
{

    int arr[10] = {1, 2, 3, 4, 5};
    int size = 5;
    int index = 0;
    int target = 5;
    bool result = search(arr, size, index, target);
    if (result)
        cout << "element found" << endl;
    else
        cout << "not found" << endl;
    return 0;
}