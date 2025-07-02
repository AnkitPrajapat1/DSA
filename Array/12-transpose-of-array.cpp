#include <iostream>
using namespace std;

void transpose(int arr[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = i; j < col; j++)
        {
            int temp=arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i]=temp;
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[][4] = {{10, 20, 30, 40},
                    {2, 3, 4, 5},
                    {6, 7, 8, 9},
                    {4, 5, 6, 7}};
    int row = 4, col = 4;
    transpose(arr, row, col);
    return 0;
}