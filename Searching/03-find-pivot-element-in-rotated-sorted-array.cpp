#include <iostream>
#include <vector>
using namespace std;


//Finds the pivot element in a rotated sorted array.

int findPivotElement(vector<int>&nums){
    int n=nums.size();
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    while(s<=e){
     if(s==e){
        return s;
     }   
     if(mid<=n-1 && nums[mid]>nums[mid+1]){
        return mid;
     }
     else if(mid>=0 && nums[mid]<nums[mid-1]){
        return mid-1;
     }
     else if(nums[s]>nums[mid]){
        e=mid-1;
     }
     else{
        s=mid+1;
     }
     mid=s+(e-s)/2;
    }

    return -1;

}
int main(){
    vector<int> arr={4,5,6,7,0,1,2}; 
    int result = findPivotElement(arr);
    if(result!=-1) cout<<"Element is "<<arr[result]<<endl;   
    return 0;
}