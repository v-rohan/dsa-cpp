#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> right;
    vector<int> left;
    int sum = 0;
    right.push_back(arr[size - 1]);
    left.push_back(arr[0]);
    for (int i = 1; i < size; i++)
        left.push_back(max(left[i - 1], arr[i]));
    for (int i = size - 2; i >= 0; i--)
        right.insert(right.begin(), max(right[0], arr[i]));
    for (int i = 0; i < size; i++)
        sum += min(right[i], left[i]) - arr[i];
    cout << sum << endl;
}