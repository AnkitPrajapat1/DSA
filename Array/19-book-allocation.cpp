// books allocaion or painters allocation

// Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.

// There are ‘m’ number of students, and the task is to allocate all the books to the students.

// Allocate books in such a way that:

// 1. Each student gets at least one book.
// 2. Each book should be allocated to only one student.
// 3. Book allocation should be in a contiguous manner.

// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.

// If the allocation of books is not possible, return -1.

// Example:
// Input: ‘n’ = 4 ‘m’ = 2
// ‘arr’ = [12, 34, 67, 90]

// Output: 113

#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int mid)
{
    int studentCount = 1;
    int pageSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
            // cout<<pageSum<<endl;
        }
        else
        {
            studentCount++;
            // cout<<"enter else "<<endl;
            if (studentCount > m || arr[i] > mid)
            {
                // cout<<"false"<<endl;
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int findPages(vector<int> &arr, int n, int m)
{
    // Write your code here.
    int s = 0;
    int sum = 0;
    int ans = -1;
    if (n < m)
        return ans;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int e = sum;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        // cout<<"MID "<<mid<<endl;
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{

    vector<int> arr = {12, 34, 67, 90};
    int n = arr.size();
    int m = 2;
    cout << findPages(arr, n, m) << endl;
    return 0;
}