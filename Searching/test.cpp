#include<iostream>
#include<vector>
using namespace std;

 int findDuplicate(vector<int>& nums) {
        int total=0;
        int xorTotal=0;
        for(auto i: nums){
          total+=i;
        }
        for(auto i:nums){
            xorTotal=xorTotal^i;
        }
      cout<<xorTotal;
       int result= total-xorTotal;
      result=result/2;
       return result;
    }

    int main(){
        vector<int>nums={1,3,4,2,2};
        int result = findDuplicate(nums);
        cout<<"Duplicate"<<result<<endl;
        return 0;
    }