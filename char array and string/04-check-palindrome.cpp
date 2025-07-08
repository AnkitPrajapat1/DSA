#include<iostream>
#include<string.h>
using namespace std;

bool checkPalindrome(char ch[]){
  
  int n=strlen(ch);
  int left=0;
  int right=n-1;
  while(left<right){
    if(ch[left]==ch[right]){
        left++;
        right--;
    }
    else{
        return false;
    }
   
  }
return true;
}
int main(){
    char ch[100];
    cout<<"enter a line: ";
    cin.getline(ch,100);
    bool result=checkPalindrome(ch);
    if(result) cout<<"Palindrome";
    else cout<<"Not a palindrome";
    // cout<<"reverse: "<<ch; 
    return 0;
}