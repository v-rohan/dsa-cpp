#include <bits/stdc++.h>
using namespace std;
int t[1000][1000];
int mcm(int *arr, int i, int j)
{
    if (i >= j)
        return t[i][j] = 0;
    int temp = -1;
    int minimum = INT_MAX;
    if (t[i][j] != -1)
        return t[i][j];
    for (int k = i; k < j; k++)
    {
        temp = mcm(arr, i, k) + mcm(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        if (temp < minimum)
            minimum = temp;
    }
    return t[i][j] = minimum;
}
int main()
{
    int arr[] = {10, 20, 30, 40, 30};
    for (int i = 0; i <= 5; i++)
        for (int j = 0; j <= 5; j++)
            t[i][j] = -1;
    cout << mcm(arr, 1, 4) << endl;
}