#include<iostream>
#include<string.h>
using namespace std;

void reverseChar(char ch[]){
    int n=strlen(ch);
  int left=0;
  int right=n-1;
  while(left<right){
    swap(ch[left],ch[right]);
    left++;
    right--;
  }
}
int main(){
    char ch[100];
    cout<<"enter a line: ";
    cin.getline(ch,100);
    reverseChar(ch);

    cout<<"reverse: "<<ch; 
    return 0;
}