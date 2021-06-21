#include <bits/stdc++.h>
using namespace std;
int mcm(int *arr, int i, int j)
{
    if (i >= j)
        return 0;
    int temp = -1;
    int minimum = INT_MAX;
    for (int k = i; k < j; k++)
    {
        temp = mcm(arr, i, k) + mcm(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        if (temp < minimum)
            minimum = temp;
    }
    return minimum;
}
int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    cout << mcm(arr, 1, 4) << endl;
}