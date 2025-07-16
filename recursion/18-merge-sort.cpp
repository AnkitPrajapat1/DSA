#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int s, int e)
{
    int mid = s + (e - s) / 2;

    int lenLeft = mid - s + 1;
    int lenRight = e - mid;

    // create left and right array
    int *left = new int[lenLeft];
    int *right = new int[lenRight];

    // copy values from original array to left array
    int k = s;
    // k-> staring index of left array values in original array
    for (int i = 0; i < lenLeft; i++)
    {
        left[i] = arr[k];
        k++;
    }

    k = mid + 1;
    // copy values from original array to right array
    for (int i = 0; i < lenRight; i++)
    {
        right[i] = arr[k];
        k++;
    }

    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;

    while (leftIndex < lenLeft && rightIndex < lenRight)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            arr[mainArrayIndex] = left[leftIndex];
            leftIndex++;
            mainArrayIndex++;
        }
        else
        {
            arr[mainArrayIndex] = right[rightIndex];
            rightIndex++;
            mainArrayIndex++;
        }
    }

    while (rightIndex < lenRight)
    {
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }
    while (leftIndex < lenLeft)
    {
        arr[mainArrayIndex] = left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }
    delete left;
    delete right;
}
void mergeSort(int arr[], int s, int e)
{
    if (s > e)
        return;
    if (s == e)
        return;

    int mid = s + (e - s) / 2;

    // recursive call for left array
    mergeSort(arr, s, mid);
    // recursive call for right array
    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}
int main()
{
    int arr[7] = {5, 3, 7, 2, 9, 1, 6};
    int n = 7;
    int s = 0;
    int e = n - 1;
    cout << "Before sorting: " << endl;
    for (auto n : arr)
    {
        cout << n << " ";
    }
    cout << endl;
    mergeSort(arr, s, e);

    cout << "After sorting: " << endl;
    for (auto n : arr)
    {
        cout << n << " ";
    }
    return 0;
}