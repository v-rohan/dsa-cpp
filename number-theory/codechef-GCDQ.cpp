/*
https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/micro-and-prime-prime-1/ 


INCOMPLETE
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define mod 1000000007
#define lli long long int
#define li long int
#define vi vector<int>

int arr[100001];

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void printGCD(int l, int r, int n)
{
    vi nums;
    cout << "break2";
    for (int i = 1; i <= n; i++)
        if (!(l <= i <= r))
            nums.push_back(arr[i]);
    sort(nums.begin(), nums.end());
    int gcde = 1;
    for (int i = 0; i <= nums.size(); i++)
        if (i == 0)
            gcde = gcd(nums[0], nums[1]), i++;
        else
        {
            if (gcde == 1)
                break;
            else
                gcde = gcd(gcde, nums[i]);
        }

    cout << gcde << endl;
}

int main()
{
    int t;
    cin >> t;
    int n, q, l, r;
    while (t--)
    {
        cin >> n >> q;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        for (int i = 1; i <= n; i++)
            cout << arr[i];
        while (q--)
        {

            cin >> l;
            cout << l;
            cin >> r;
            cout << r;
            cout << "break1";
            printGCD(l, r, n);
        }
    }
}