#include <bits/stdc++.h>
using namespace std;
int solve(string s, int i, int j, bool need)
{
    if (i > j)
        return false;
    else if (i == j && need == true)
        return s[i] == 'T';
    else if (i == j && need == false)
        return s[i] == 'F';
    else
    {
        int ans = 0;
        for (int k = i + 1; k <= j - 1; k = k + 2)
        {
            int slt = solve(s, i, k - 1, true);
            int srt = solve(s, k + 1, j, true);
            int srf = solve(s, k + 1, j, false);
            int slf = solve(s, i, k - 1, false);
            if (need == true)
            {
                if (s[k] == '|')
                {
                    ans = ans + srt * slf + slt * srf + slt * srt;
                }
                else if (s[k] == '&')
                {
                    ans = ans + srt * slt;
                }
                else
                {
                    ans = ans + srt * slf + slt * srf;
                }
            }
            else
            {
                if (s[k] == '|')
                {
                    ans = ans + srf * slf;
                }
                else if (s[k] == '&')
                {
                    ans = ans + srt * slf + slt * srf + slf * srf;
                }
                else
                {
                    ans = ans + srt * slt + slf * srf;
                }
            }
        }
        return ans;
    }
}
int main()
{
    string a;
    cin >> a;
    cout << solve(a, 0, a.length() - 1, true) << endl;
}