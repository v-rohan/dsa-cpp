#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x = 5;
    int k = 3;
    int arr[] = {10, 2, 14, 4, 7, 6};
    priority_queue<pair<int, int>> maxH;
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        maxH.push(make_pair(abs(arr[i] - x), arr[i]));
        if (maxH.size() > k)
            maxH.pop();
    }
    while (!maxH.empty())
    {
        cout << maxH.top().second << endl;
        maxH.pop();
    }
}