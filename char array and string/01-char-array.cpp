#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char ch[10];
    char line[100];
    int index = 0;
    // cout<<"Enter: ";
    // cin>>ch;

    // while(ch[index]!='\0'){
    //     index++;
    // }
    // cout<<"Length is: "<<index<<endl;
    // cout<<"Length is: "<<strlen(ch)<<endl;

    cout << "enter a line: ";
    cin.getline(line, 100);

    cout << "length: " << strlen(line);
    return 0;
}