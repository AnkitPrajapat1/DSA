#include<iostream>
#include<vector>
using namespace std;


int binarySearch(vector<int>&arr,int size,int val){
    int start=0;
    int end=size-1;
    int mid=start+(end-start)/2;

    while (start<=end)
    {
        if(arr[mid]==val){
        return mid;
    }
    else if(arr[mid]>val){
        end=mid-1;
    }
    else{
        start=mid+1;
    }
    mid=start+(end-start)/2;

    }
    return -1;
   
}
int firstOccurence(vector<int>&arr,int size,int val){
    int start=0;
    int end=size-1;
    int mid=start+(end-start)/2;
    int result=-1;
    while (start<=end)
    {
        if(arr[mid]==val){
        result=mid;
        end=mid-1;
        // start=mid+1 for last occurence in sorted array
    }
    else if(arr[mid]>val){
        end=mid-1;
    }
    else{
        start=mid+1;
    }
    mid=start+(end-start)/2;

    }
    return result;
   
}
int lastOccurence(vector<int>&arr,int size,int val){
    int start=0;
    int end=size-1;
    int mid=start+(end-start)/2;
    int result=-1;
    while (start<=end)
    {
        if(arr[mid]==val){
        result=mid;
        start=mid+1;
    }
    else if(arr[mid]>val){
        end=mid-1;
    }
    else{
        start=mid+1;
    }
    mid=start+(end-start)/2;

    }
    return result;
   
}

int totalOccurence(vector<int>&arr,int size,int val){
    int first=firstOccurence(arr,size,val);
    int last=lastOccurence(arr,size,val);
    int total=last-first+1;
    return total;
}

int missingElement(vector<int>&arr,int size){
      int start=0;
    int end=size-1;
    int mid=start+(end-start)/2;
    int result=-1;
    while (start<=end)
    {
        if(arr[mid]-1==mid){   //1,2,3,5,6,7,8,9,10
        start=mid+1;
    }
    else{
        end=mid-1;
    }
    mid=start+(end-start)/2;

    }
    return start+1;
}
int main(){
    vector<int>arr={2,5,7,7,7,66,86,95,113};
    int size=arr.size();
    int val=7;
    // int result=binarySearch(arr,size,val);
    // if(result==-1) cout<<"element not found"<<endl;
    // else cout<<"element found at index "<<result<<endl;


    // int result=firstOccurence(arr,size,val);
    // if(result!=-1) cout<<"First occurence of element is found at "<<result<<endl;
    // else cout<<"element not found"<<endl;


    // int result=totalOccurence(arr,size,val);
    // if(result!=-1) cout<<"total occurence of element is "<<result<<endl;
    // else cout<<"element not found"<<endl;
    

    vector<int>nums={1,2,3,4,5,6,7,8,9};
    int sizeOfNums=nums.size();
    int result=missingElement(nums,sizeOfNums);
     if(result!=-1) cout<<"missing element is "<<result<<endl;
    else cout<<"element not found"<<endl;

    return 0;
}