#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < size; i++)
        minHeap.push(arr[i]);
    int cost = 0;
    while (minHeap.size() != 1)
    {
        int a = minHeap.top();
        minHeap.pop();
        int temp = a + minHeap.top();
        minHeap.pop();
        minHeap.push(temp);
        cost += temp;
    }
    cout << cost << endl;
    minHeap.pop();
}