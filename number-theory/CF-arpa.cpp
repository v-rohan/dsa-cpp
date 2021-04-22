/*
https://codeforces.com/problemset/problem/742/A
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// #define mod 1000000007
#define lli long long int
#define li long int
#define vi vector<int>

int power(int num, lli pow, int mod)
{
    int res = 1;
    while (pow)
    {
        if (pow % 2)
        {
            res = (res % mod * num % mod) % mod;
            pow--;
        }
        else
        {
            num = (num % mod * num % mod) % mod;
            pow /= 2;
        }
    }

    return res;
}

int main()
{
    int num = 8;
    lli n;
    cin >> n;
    cout << power(8, n, 10) << endl;
}