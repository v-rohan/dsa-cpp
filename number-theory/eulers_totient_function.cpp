#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define mod 1000000007
#define lli long long int
#define li long int
#define vi vector<int>
bool sieve[100001];

lli phi(lli n)
{
    lli res = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res = res * (i - 1) / i;
            while (n % i == 0)
                n /= i;
        }
    }

    if(n>1)
    res /= n, res *= n-1;

    return res;
}
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << phi(n) << endl;
    }
}