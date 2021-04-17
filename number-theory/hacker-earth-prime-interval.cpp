/*
https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/prime-interval/
Number theory - Primality
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define mod 1000000007
#define lli long long int
#define li long int
#define vi vector<int>

bool sieve[900001];
vi primes;
bool isPrime(int a)
{
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int l, r;
    cin >> l >> r;
    for (int i = l>2?l:2; i <= r; i++)
        if (isPrime(i))
            cout << i << " ";
}