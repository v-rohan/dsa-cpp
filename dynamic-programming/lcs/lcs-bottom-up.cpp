#include <bits/stdc++.h>
using namespace std;
int t[1000][1000];
int lcs(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (t[n][m] != -1)
        return t[n][m];
    else
    {
        if (x[n - 1] == y[m - 1])
            return t[n][m] = 1 + lcs(x, y, n - 1, m - 1);
        else
            return t[n][m] = max(lcs(x, y, n, m - 1), lcs(x, y, n - 1, m));
    }
}
int main()
{
    string x;
    string y;
    cin >> x >> y;
    int n = x.length();
    int m = y.length();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            t[i][j] = -1;
    cout << lcs(x, y, n, m) << endl;
}