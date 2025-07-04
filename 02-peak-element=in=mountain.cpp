 #include<iostream>
 #include<vector>
 using namespace std;
 
 int peakIndexInMountainArray(vector<int>& arr) {
        int size=arr.size();
        int start=0;
        int end=size-1;
        int mid=start+(end-start)/2;
        while(start<end){
            if(arr[mid]<arr[mid+1]){
                start=mid+1;
            }
            else end=mid;
            
        mid=start+(end-start)/2;

        }
        return start;
    }

int main(){

    vector<int>arr={1,3,7,5,4,2,1};
    cout<<"Peak index is "<<peakIndexInMountainArray(arr) <<" with value "<<arr[peakIndexInMountainArray(arr)]<<endl;
    return 0;
}    