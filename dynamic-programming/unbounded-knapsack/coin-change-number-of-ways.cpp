#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[] = {1, 2, 3};
    int size = 3;
    int n = 5;
    int t[size + 1][n + 1];
    for (int i = 0, j = 0; j <= n; j++)
        t[i][j] = 0;
    for (int i = 0, j = 0; i <= size; i++)
        t[i][j] = 1;
    for (int i = 1; i <= size; i++)
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j] + t[i][j - a[i - 1]];
            }
            else
                t[i][j] = t[i - 1][j];
        }
    cout << t[size][n] << endl;
}