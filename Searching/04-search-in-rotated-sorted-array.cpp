#include <iostream>
#include <vector>
using namespace std;

int findPivotElement(vector<int> &nums)
{
    int n = nums.size();
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (s == e)
        {
            return s;
        }
        if (mid <= n - 1 && nums[mid] > nums[mid + 1])
        {
            return mid;
            
        }
        else if (mid >= 0 && nums[mid] < nums[mid - 1])
        {
            return mid - 1;
            

        }
        else if (nums[s] > nums[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }


    return -1;
}

int binarySearch(vector<int> &nums, int s, int e, int target)
{
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (nums[mid] == target)
        {
            return mid;
            cout<<mid<<endl;
        }
        else if (nums[mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int search(vector<int> &nums, int target)
{
    int pivotIndex = findPivotElement(nums);
    int ans = -1;
    int n=nums.size();
    // search in A
    if (target >= nums[0] && target <= nums[pivotIndex])
    {
        ans=binarySearch(nums,0,pivotIndex,target);
    }
    else{
        ans=binarySearch(nums,pivotIndex+1,n-1,target);
    }
    return ans;
}
int main()
{
    vector<int> arr={4,5,6,7,0,1,2}; 
    int result = search(arr,0);
    if(result!=-1) cout<<"Element is found"<<endl; 
    return 0;
}