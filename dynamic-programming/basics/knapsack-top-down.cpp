#include <bits/stdc++.h>
using namespace std;

int t[100][100];
int knapsack(int *wt, int *val, int w, int n)
{
    for (int i = 0, j = 0; j < w + 1; j++)
        t[i][j] = 0;
    for (int j = 0, i = 0; i < n + 1; i++)
        t[i][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= w; j++)
        {
            if (wt[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
            else
            {
                t[i][j] = max((val[i - 1] + t[i - 1][j - wt[i - 1]]), t[i - 1][j]);
            }
        }
    return t[n][w];
}
int main()
{
    memset(t, -1, sizeof(t));
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int weight = 7;

    cout << knapsack(wt, val, weight, (sizeof(wt) / sizeof(wt[0]))) << endl;
}
