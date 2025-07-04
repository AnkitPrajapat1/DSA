// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

#include <iostream>
#include <utility>
using namespace std;

void sortColors(int arr[], int size)
{
    int left = 0;
    int right = size - 1;
    int index = 0;
    while (index <= right)
    {
        if (arr[index] == 0)
        {
            swap(arr[left], arr[index]);
            left++;
            index++;
        }

        else if (arr[index] == 2)
        {
            swap(arr[index], arr[right]);
            right--;
        }
        else
            index++;
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
    int arr[] = {1, 0, 2, 1, 0, 2, 2, 1, 0, 2, 2, 0, 2, 2, 1, 1, 1}; 
    int size = 17;
    sortColors(arr, size);
    print(arr, size);
    return 0;
}