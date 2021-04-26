/*
https://www.spoj.com/problems/PON/

*/

#include <iostream>
#include <vector>
#include <algorithm>
#define mod 1000000007
#define lli long long int
#define li long int
#define vi vector<int>

using namespace std;

lli mulmod(lli a, lli b, lli c)
{
    lli x = 0, y = a % c;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % c;
        }
        y = (y * 2LL) % c;
        b /= 2;
    }
    return x % c;
}

lli binPowerMod(lli base, lli pow, lli modulus)
{
    lli res = 1;
    while (pow)
    {
        if (pow % 2)
            res = mulmod(res, base, modulus), pow--;
        else
            base = mulmod(base, base, modulus), pow /= 2;
    }
    return res;
}

bool isFermatPrime(lli n)
{
    int iter = 5;
    if (n < 4)
        return n == 2 | n == 3;
    for (int i = 1; i <= iter; i++)
    {
        lli a = 2 + rand() % (n - 3);
        if (binPowerMod(a, n - 1, n) != 1)
            return false;
    }
    return true;
}

int main()
{
    int t = 0;
    cin >> t;
    lli a;
    while (t--)
    {
        cin >> a;
        if (isFermatPrime(a))
            cout << "YES"
                 << "\n";
        else
            cout << "NO"
                 << "\n";
    }
}