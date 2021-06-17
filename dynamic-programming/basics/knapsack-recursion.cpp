#include <bits/stdc++.h>
using namespace std;

int knapsack(int *wt, int *val, int w, int n)
{
    if (n == 0 || w == 0)
        return 0;
    if (wt[n] <= w)
        return max((val[n] + knapsack(wt, val, w - wt[n], n - 1)), knapsack(wt, val, w, n - 1));
    else
        return knapsack(wt, val, w, n - 1);
}
int main()
{
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int weight = 7;

    cout << knapsack(wt, val, weight, (sizeof(wt) / sizeof(wt[0]) - 1)) << endl;
}
