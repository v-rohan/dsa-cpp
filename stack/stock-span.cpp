#include <bits/stdc++.h>
using namespace std;

vector<int> ngl(int *arr, int size)
{
    stack<int> st;
    vector<int> ans;
    for (int i = 0; i < size; i++)
    {
        if (st.size() == 0)
            ans.push_back(i + 1);
        else if (st.size() > 0 && arr[st.top()] > arr[i])
        {
            ans.push_back(i - st.top());
        }
        else if (st.size() > 0 && arr[st.top()] < arr[i])
        {
            while (st.size() > 0 && arr[st.top()] < arr[i])
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                ans.push_back(i + 1);
            }
            else
            {
                ans.push_back(i - st.top());
            }
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans = ngl(arr, sizeof(arr) / sizeof(arr[0]));
    for (auto i : ans)
        cout << i << " ";
}