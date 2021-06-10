#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    int count = 0;
    priority_queue<int, vector<int>, greater<int>> minH;
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        minH.push(arr[i]);
        if (minH.size() > k)
        {
            arr[count++] = minH.top();
            minH.pop();
        }
    }
    while (count < (sizeof(arr) / sizeof(arr[0])))
    {
        arr[count++] = minH.top();
        minH.pop();
    }

    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        cout << arr[i] << " ";
    }
}