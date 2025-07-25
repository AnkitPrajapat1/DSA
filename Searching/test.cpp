#include <iostream>
#include <vector>
#include <string>
using namespace std;

// int myAtoi(string s)
// {
//   int n = s.length();
//   string ans = "";
//   int i = 0;
//   while (s[i] == ' ')
//   {
//     i++;
//   }
//   // if(s[i]=='-'){
//   //     ans.push_back(s[i]);
//   //     i++;
//   // }

//   for (int i = 0; i < n; i++)
//   {
//     if (isalpha(s[i]))
//       break;
//     else
//       ans.push_back(s[i]);
//   }
//   return stoi(ans);
// }

    int myAtoi(string s) {
        int n=s.length();
        int ans=0;
        int i=0;
        while(s[i]==' ' || s[i]==0){ i++;}
        // if(s[i]=='-'){
        //     ans.push_back(s[i]);
        //     i++;
        // } 
        
        // for(int i=0;i<n;i++){
        //     if(isalpha(s[i])) break;
        //     else ans.push_back(s[i]);
        // }
        while(i<n){
            if(isalpha(s[i])) break;
            int num= s[i]-48;
            cout<<num<<endl;
            ans=ans*10+num;
            i++;
        }
        return ans;
    }
int main()
{
  string str = " 42";
  cout << myAtoi(str);
  return 0;
}