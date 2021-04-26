//https://www.codechef.com/problems/COPR16G

#include <iostream>
#include <vector>
#include <algorithm>
#define mod 1000000007
#define lli long long int
#define li long int
#define endl '\n'
#define REP(i, n) for (int i = 1; i <= n; i++)
#define vi vector<int>
int phi[1000001];

using namespace std;

uint64_t gcd(uint64_t a, uint64_t b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    uint64_t a, b;
    while (t--)
    {
        cin >> a >> b;
        if (gcd(a, b) != 1)
            cout << -1 << endl;
        else
        {
            uint64_t res = a * b - a - b + 1;
            cout << res << endl;
        }
    }
}