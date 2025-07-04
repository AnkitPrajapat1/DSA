#include <iostream>
#include <utility>
using namespace std;

void sortNegPos(int arr[], int size)
{
    int i = 0;
    for (int index = 0; index < size; index++)
    {
        if (arr[index] < 0)
        {
            swap(arr[i], arr[index]);
            i++;
        }
    }
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{

    int arr[] = {20, -7, 32, -8, 5, 40, 80, -27, 65};
    int size = 9;
    sortNegPos(arr, size);
    print(arr, size);
    return 0;
}