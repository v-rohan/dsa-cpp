/*https://codeforces.com/problemset/problem/1485/A */
#include <iostream>
#include <vector>
#include <algorithm>
#define mod 1000000007
#define lli long long int
#define li long int
#define endl '\n'
#define vi vector<int>

using namespace std;

bool sieve[1000001];
vi primes;

void buildsieve()
{
    for (int i = 2; i * i <= 1000000; i++)
        if (sieve[i] == false)
        {
            for (int j = 2*i; j <= 1000000; j += i)
                sieve[j] = true;
        }
    for (int i = 2; i <= 1000000; i++)
        if (sieve[i] == false)
            primes.push_back(i);
}

int main()
{
    int t;
    cin >> t;
    buildsieve();
    int d;
    while (t--)
    {
        cin >> d;
        int num2 = *(std::lower_bound(primes.begin(), primes.end(), 1+d));
        int num3 = *(std::lower_bound(primes.begin(), primes.end(), num2 + d));
        lli ans = 1LL * num2 * num3;
        cout << ans << endl;
    }
}