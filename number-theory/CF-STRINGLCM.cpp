/*
https://codeforces.com/problemset/problem/1473/B

INCOMPLETE
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define mod 1000000007
#define lli long long int
#define li long int
#define vi vector<int>
#define endl '\n'

using namespace std;

int main()
{
    int t;
    cin >> t;
    string a, b;
    while (t--)
    {
        cin >> a >> b;
        if (a[0] != b[0] || a[a.length() - 1] != b[b.length() - 1])
            cout << -1 << endl;
        else
        {
            int hcf = __gcd(a.length(), b.length());
            string str1 = "";
            string str2 = "";
            for (int i = 1; i <= b.length() / hcf; i++)
                str1 += a;
            for (int i = 1; i <= a.length() / hcf; i++)
                str2 += b;

            if (str1 == str2)
                cout << str1 << endl;
            else
                cout << -1 << endl;
        }
    }
}