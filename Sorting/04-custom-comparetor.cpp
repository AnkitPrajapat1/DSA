#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// to sort in decreasing order
bool commarator(int &a, int &b)
{
    return a > b;
}

// to sort vector based on second index
bool vectorComp(vector<int> &a, vector<int> &b)
{
    return a[1] > b[1];
}
void printvv(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        vector<int> &temp = arr[i];
        int a = temp[0];
        int b = temp[1];
        cout << a << " " << b << endl;
    }
    cout << endl;
}
int main()
{
    // vector<int>arr={4,8,2,5,4,1};

    // sort(arr.begin(),arr.end(),commarator);

    // for(int i=0;i<arr.size();i++){
    //     cout<<arr[i]<<" ";
    // }

    vector<vector<int>> arr;
    int n;
    cout << "input size: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cout << "Enter a, b: ";
        cin >> a >> b;
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);
        arr.push_back(temp);
    }
    printvv(arr);

    sort(arr.begin(), arr.end(), vectorComp);
    printvv(arr);

    return 0;
}