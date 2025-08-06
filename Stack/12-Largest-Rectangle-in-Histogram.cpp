#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// firtst approach

vector<int> nextSmallerElement(vector<int> &arr)
{
    vector<int> ans(arr.size());
    stack<int> st;
    st.push(-1);

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
vector<int> prevSmallerElement(vector<int> &arr)
{
    vector<int> ans(arr.size());
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < arr.size(); i++)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    vector<int> next = nextSmallerElement(heights);
    for (int i = 0; i < next.size(); i++)
    {
        if (next[i] == -1)
        {
            next[i] = next.size();
        }
    }

    vector<int> prev = prevSmallerElement(heights);
    int maxArea = INT_MIN;
    for (int i = 0; i < heights.size(); i++)
    {
        int length = heights[i];
        int width = next[i] - prev[i] - 1;
        int currArea = length * width;
        maxArea = max(maxArea, currArea);
    }
    return maxArea;
}

// optimized

int optimizedLargestRectangleArea(vector<int> &heights)
{
    stack<int> st;
    int maxAns = 0;
    int nse;
    int pse;
    int n = heights.size();
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            int element = st.top();
            st.pop();
            nse = i;
            pse = st.empty() ? -1 : st.top();
            int temp = heights[element] * (nse - pse - 1);
            maxAns = max(maxAns, temp);
        }
        st.push(i);
    }
    while (!st.empty())
    {
        nse = n;
        int element = st.top();
        st.pop();
        pse = st.empty() ? -1 : st.top();
        int temp = heights[element] * (nse - pse - 1);
        maxAns = max(maxAns, temp);
    }
    return maxAns;
}
int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << optimizedLargestRectangleArea(heights) << endl;
    return 0;
}