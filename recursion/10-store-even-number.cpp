#include <iostream>
#include <vector>
using namespace std;

void even(int arr[], int size, int index, vector<int> &ans)
{
    if (index >= size)
    {
        return;
    }
    if (arr[index] % 2 == 0)
    {
        ans.push_back(arr[index]);
    }
    return even(arr, size, index + 1, ans);
}
int main()
{

    int arr[6] = {2, 6, 12, 5, 7, 30};
    int size = 6;
    int index = 0;
    vector<int> ans;
    even(arr, size, index, ans);
    for (auto n : ans)
    {
        cout << n << " ";
    }
    // cout<<"Ans is: ";
    return 0;
}