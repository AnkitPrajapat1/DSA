#include<iostream>
#include<vector>
using namespace std;

void change(string &str){
  // cout<<"enter";
        int arr[26]={0};
        char ch='a';
        for(char s:str){
          // cout<<s<<endl;
          // bool a=(s-ch==0);
          
            if(arr[s-'a']==0){
            arr[s-'a']=ch;
            ch++;
            }
        }
        for(int i=0;i<str.length();i++){
            str[i]=arr[str[i]-'a'];
            // cout<<str[i]<<" ";
        }
    }

    int main(){
        string str="add";
        cout<<str<<endl;
        change(str);
        cout<<str;
        return 0;
    }