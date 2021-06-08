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
    int arr[] = {2, 3, 3, 2};
    vector<int> left = nsl(arr, sizeof(arr) / sizeof(arr[0]));
    vector<int> right = nsr(arr, sizeof(arr) / sizeof(arr[0]));
    int area = INT_MIN;
    for (int i = 0; i < left.size(); i++)
    {
       // cout << i << " " << arr[i] << " " << right[i] << " " << left[i] << "\n";
        area = max(area, (arr[i] * (right[i] - left[i] - 1)));
    }
    cout << area << "\n";
}