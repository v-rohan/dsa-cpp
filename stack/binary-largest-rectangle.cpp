#include <bits/stdc++.h>
using namespace std;
vector<int> nsl(int *arr, int size)
{
    stack<int> st;
    vector<int> ans;
    for (int i = 0; i < size; i++)
    {
        if (st.empty())
            ans.push_back(-1);
        else if (!st.empty() && arr[st.top()] >= arr[i])
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top());
        }
        else
        {
            ans.push_back(st.top());
        }
        st.push(i);
    }
    return ans;
};
vector<int> nsr(int *arr, int size)
{
    stack<int> st;
    vector<int> ans;
    for (int i = size - 1; i >= 0; i--)
    {
        if (st.empty())
            ans.push_back(size);
        else if (!st.empty() && arr[st.top()] >= arr[i])
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (st.empty())
                ans.push_back(size);
            else
                ans.push_back(st.top());
        }
        else
        {
            ans.push_back(st.top());
        }
        st.push(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
};
int main()
{
    int arr[4][4] = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};
    int rows = sizeof(arr) / sizeof(arr[0]);
    int columns = sizeof(arr[0]) / sizeof(arr[0][0]);

    for (int j = 1; j < rows; j++)
        for (int k = 0; k < columns; k++)
            if (arr[j][k] == 1)
                arr[j][k] += arr[j - 1][k];
    int maxim = INT_MIN;
    for (int j = 0; j < rows; j++)
    {
        vector<int> left = nsl(arr[j], columns);
        vector<int> right = nsr(arr[j], columns);
        int area = INT_MIN;
        for (int i = 0; i < left.size(); i++)
        {
            area = max(area, (arr[j][i] * (right[i] - left[i] - 1)));
            //cout << arr[j][i] << " ";
        }
        maxim = max(maxim, area);
       // cout << area << " \n";
    }

    cout << maxim << "\n";
}