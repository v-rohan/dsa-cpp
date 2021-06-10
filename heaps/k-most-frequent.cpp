#include <bits/stdc++.h>
#define ppi pair<int, int>
using namespace std;

int main()
{
    int arr[] = {1, 1, 1, 3, 45, 4, 5, 4, 4, 4, 45, 45, 45, 45, 45, 45, 5, 2, 3, 0, 0, 0, 0, 0, 0};
    int k = 3;
    int size = sizeof(arr) / sizeof(arr[0]);
    unordered_map<int, int> mp;
    for (int i = 0; i < size; i++)
    {
        if (mp.find(arr[i]) == mp.end())
            mp.insert({arr[i], 1});
        else
            mp[arr[i]]++;
    }
    priority_queue<ppi, vector<ppi>, greater<ppi>> minH;
    for (auto i : mp)
    {
        minH.push(make_pair(i.second, i.first));
        if (minH.size() > k)
            minH.pop();
    }
    while (!minH.empty())
    {
        cout << minH.top().second << "  " << minH.top().first << endl;
        minH.pop();
    }
}