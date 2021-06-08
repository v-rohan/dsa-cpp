#include <bits/stdc++.h>
using namespace std;

vector<int> nsl(int *arr, int size)
{
    stack<int> st;
    vector<int> val;
    for (int i = size - 1; i > -1; i--)
    {
        if (st.size() == 0)
            val.push_back(-1);
        else if (st.size() > 0 && st.top() < arr[i])
            val.push_back(st.top());
        else if (st.size() > 0 && st.top() >= arr[i])
        {
            while (st.size() > 0 && st.top() >= arr[i])
                st.pop();
            if (st.size() == 0)
                val.push_back(-1);
            else
                val.push_back(st.top());
        }
        st.push(arr[i]);
    }
    reverse(val.begin(), val.end());
    return val;
};
int main()
{
    int arr[] = {4, 5, 2, 10, 8};
    vector<int> ans = nsl(arr, sizeof(arr) / sizeof(arr[0]));
    for (auto i : ans)
        cout << i << "\n";
}