/*
https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/micro-and-prime-prime-1/ 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define mod 1000000007
#define lli long long int
#define li long int
#define vi vector<int>

bool sieve[1000001];
int pp[1000001];
void buildsieve()
{
    sieve[0] = sieve[1] = true;
    for (int i = 2; i * i <= 1000000; i++)
        if (sieve[i] == false)
            for (int j = i * i; j <= 1000000; j += i)
                sieve[j] = true;

    int count = 0;
    for (int i = 2; i <= 1000000; i++){
        if (!sieve[i])
           count++;
        if(sieve[count]==false)
        pp[i]=1;
    }
    for (int i = 2; i <= 1000000; i++)
            pp[i] += pp[i-1];
}
int main()
{
    int t = 0;
    cin >> t;
    buildsieve();
    int l, r;
    while (t--)
    {
        cin >> l >> r;
        cout << pp[r] - pp[l-1] << endl;
    }
}