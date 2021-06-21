#include <bits/stdc++.h>
using namespace std;
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
    else if (isPalin(s, i, j) == true)
        return 0;
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
        return mn;
    }
}
int main()
{
    string inputString;
    cin >> inputString;
    cout << solve(inputString, 0, inputString.length() - 1) << endl;
}