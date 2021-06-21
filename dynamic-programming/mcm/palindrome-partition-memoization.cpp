#include <bits/stdc++.h>
using namespace std;
int t[1001][1001];
bool isPalin(string s, int start, int end)
{
    string temp = s.substr(start, end - start + 1);
    string temp2 = temp;
    reverse(temp.begin(), temp.end());
    return temp == temp2;
}
int solve(string s, int i, int j)
{
    if (i >= j)
        return 0;
    else if (t[i][j] != -1)
        return t[i][j];
    else if (isPalin(s, i, j) == true)
        return t[i][j] = 0;
    else
    {
        int mn = INT_MAX;
        int temp = -1;
        for (int k = i; k < j; k++)
        {
            temp = solve(s, i, k) + solve(s, k + 1, j) + 1;
            if (temp < mn)
                mn = temp;
        }
        return t[i][j] = mn;
    }
}
int main()
{
    memset(t, -1, sizeof(t));
    string inputString;
    cin >> inputString;
    cout << solve(inputString, 0, inputString.length() - 1) << endl;
}