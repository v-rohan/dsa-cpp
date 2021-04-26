/*
    https://www.codechef.com/problems/QNUMBER
    */
#include <bits/stdc++.h>
#define mod 1000000007
#define lli long long int
#define ii pair<lli, lli>
#define li long int
//#define endl '\n'
#define REP(i, n) for (int i = 1; i <= n; i++)
#define vi vector<int>

using namespace std;
map<lli, lli> PF;
lli totalF = 1;

void factorise(lli n)
{
    for (lli i = 2; i * i <= n; i++)

        if (n % i == 0)
        {
            int count = 0;
            while (n % i == 0)
                n /= i, count++;
            PF[i] = count;
            totalF *= (count + 1);
        }

    if (n > 1)
        PF[n] = 1, totalF *= 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lli t, n, q, k;
    cin >> n >> q;
    factorise(n);
    while (q--)
    {
        cin >> t >> k;
        if (t == 1)
        {
            lli res = 1;
            for (ii factor : PF)
            {
                lli count = 0;
                while (k % factor.first == 0)
                    k /= factor.first, count++;
                res *= min(factor.second, count) + 1;
            }
            cout << res << endl;
        }
        else if (t == 2)
        {
            lli res = 1;
            for (ii factor : PF)
            {

                lli count = 0;
                while (k % factor.first == 0)
                    k /= factor.first, count++;
                if (count > factor.second)
                {
                    res = 0;
                    break;
                }

                res *= (factor.second - count + 1);
            }
            if (k > 1)
                res = 0;
            cout << res << endl;
        }
        else
        {
            lli res = 1;
            for (ii factor : PF)
            {

                lli count = 0;
                while (k % factor.first == 0)
                    k /= factor.first, count++;
                if (count > factor.second)
                {
                    res = 0;
                    break;
                }

                res *= (factor.second - count + 1);
            }
            if (k > 1)
                res = 0;
            cout << totalF - res << endl;
        }
    }
}