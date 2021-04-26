/*https://codeforces.com/problemset/problem/1485/A */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define mod 1000000007
#define lli long long int
#define li long int
#define vi vector<int>

lli solution(lli a, lli b)
{
    if(a==b)return 2;
    if(b>a) return 1;
    lli bufa =a;
    lli solu=10000000000;
    lli current=0;
    for(int i=b;i<=a;i++){
        if(i==1)continue;
        current=llabs(b-i);
        if(current>solu)break;
        while(bufa){
            bufa /= i;
            current++;
        }
        bufa=a;
        solu=min(current,solu);
    }
    return solu;
}
int main()
{
    int t;
    lli a, b = 0;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cout << solution(a, b) << '\n';
    }
}