/*
https://www.spoj.com/problems/TDKPRIME/
Number theory - Sieve of Erastothenes
*/

#include <iostream>
#include <vector>
using namespace std;
#define mod 1000000007
#define lli long long int
#define li long int
#define vi vector<int>

bool sieve[90000001];
vi primes;
void buildsieve()
{
    sieve[0] = sieve[1] = true;
    for (int i = 2; i * i <= 90000000; i++)
        if (sieve[i] == false)
            for (int j = i * i; j <= 90000000; j += i)
                sieve[j] = true;

    for (int i = 2; i <= 90000000; i++)
        if (!sieve[i])
            primes.push_back(i);
};
int main()
{
    int t = 0;
    cin >> t;
    buildsieve();
    li n;
    while (t--)
    {
        cin >> n;

        cout << primes[n-1] << endl;
    }
}