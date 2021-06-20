#include <bits/stdc++.h>
using namespace std;

int main()
{
    string x, y;
    cin >> x >> y;
    int n = x.length();
    int m = y.length();
    int t[n + 1][m + 1];
    for (int i = 0, j = 0; i <= n; i++)
        t[i][j] = 0;
    for (int i = 0, j = 0; j <= m; j++)
        t[i][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (x[i - 1] == y[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    cout << t[n][m] << endl;
}