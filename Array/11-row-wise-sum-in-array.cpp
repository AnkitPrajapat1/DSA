#include <iostream>
using namespace std;

void rowWiseSum(int arr[][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum = sum + arr[i][j];
        }
        cout << "Some of row " << i + 1 <<  " is " << sum<<endl;
    }
}
void colWiseSum(int arr[][3], int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        int sum = 0;
        for (int j = 0; j < row; j++)
        {
            sum = sum + arr[j][i];
        }
        cout << "Some of col " << i + 1 <<  " is " << sum<<endl;
    }
}
int main()
{
    int arr[3][3] = {{4, 8, 12},
                     {3, 6, 9},
                     {5, 10, 15}};
    int row = 3, col = 3;

    rowWiseSum(arr, row, col);
    colWiseSum(arr, row, col);
    return 0;
}