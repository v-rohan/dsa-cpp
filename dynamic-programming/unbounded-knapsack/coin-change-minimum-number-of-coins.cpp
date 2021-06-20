#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[] = {1, 5, 2};
    int size = 3;
    int n = 5;
    int t[size + 1][n + 1];
    for (int i = 0, j = 0; j <= n; j++)
        t[i][j] = -1;
    for (int i = 0, j = 0; i <= size; i++)
        t[i][j] = 0;
    for (int i = 1; i <= size; i++)
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] <= j)
            {
                if (t[i - 1][j] == -1 && t[i][j - a[i - 1]] == -1)
                    t[i][j] = -1;
                else if (t[i - 1][j] == -1 || t[i][j - a[i - 1]] == -1)
                    t[i][j] = max(1 + t[i][j - a[i - 1]], t[i - 1][j]);
                else
                    t[i][j] = min(1 + t[i][j - a[i - 1]], t[i - 1][j]);
            }
            else
                t[i][j] = t[i - 1][j];
        }
    cout << t[size][n] << endl;
}