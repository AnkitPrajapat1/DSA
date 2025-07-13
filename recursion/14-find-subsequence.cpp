#include <iostream>
#include <limits.h>
using namespace std;

void subsequence(string &s, int size, int index, string output)
{
    if (index >= size)
    {
        cout << output << " ";
        return;
    }
    char ch = s[index];
    subsequence(s, size, index + 1, output);
    output.push_back(ch);
    subsequence(s, size, index + 1, output);
}
int main()
{

    string s = "abcd";
    string output = "";
    int size = s.length();
    int index = 0;
    subsequence(s, size, index, output);
    return 0;
}