/*
https://www.spoj.com/problems/PRIME1/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define mod 1000000007
#define lli long long int
#define li long int
#define vi vector<long long int>
bool sieve[100001];
vi primes;
void buildsieve()
{
    for (int i = 2; i * i <= 100000; i++)
    {
        if (!sieve[i])
        {
            for (int j = 2 * i; j <= 100000; j += i)
                sieve[j] = true;
            primes.push_back(i);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    lli m, n;
    buildsieve();
    while (t--)
    {
        cin >> m >> n;
        if (m == 1)
            m++;
        lli dif = n-m;
        lli arr[dif + 1];
        std::fill(arr, arr+dif+1,0);
        for (auto it = primes.begin(); ((*it) * (*it) <= n)&&(it!=primes.end()); it++)
        {
            for (lli a = ((m / (*it)) * *it) >= m ? ((m / (*it)) * *it) : (((m / (*it)) * *it) + *it); a <= n; a += *it)
            {
                if (*it != a)
                    arr[a - m] = 1;
            }
        }

        for (lli i = 0; i <= dif; i++)
            if (arr[i] == 0)
                cout << m + i << endl;
    }
}


/* WA 

REVIEWWWWW
*/