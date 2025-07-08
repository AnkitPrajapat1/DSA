#include <iostream>
#include <string.h>
using namespace std;

int main()
{

    char line[100];
    int index = 0;
    cout << "enter a line: ";
    cin.getline(line, 100);

    cout << "length: " << strlen(line);
    while (line[index] != '\0')
    {
        if (line[index] == '@')
        {
            line[index] = ' ';
        }
        index++;
    }
    cout << endl
         << line;
    return 0;
}