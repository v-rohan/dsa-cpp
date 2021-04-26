// https://www.spoj.com/problems/CEQU/

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

lli gcd(lli a, lli b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

bool solutionExists(lli a, li b, lli c)
{
    if (c == 0)
        return true;
    lli hcf = gcd(a, b);
    if (c % hcf == 0)
        return true;
    return false;
}

int main()
{
    int t;
    cin >> t;
    lli a, b, c;
    REP(i, t)
    {
        /* code */
        cin >> a >> b >> c;
        cout << "Case " << i << ": ";
        if (solutionExists(a, b, c))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}