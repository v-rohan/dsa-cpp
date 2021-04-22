/*
https://www.codechef.com/submit/GCDMOD
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define modulo 1000000007
#define lli long long int
#define li long int
#define vi vector<int>

lli power(lli a, lli n, lli mod){
    int res =1;
    while(n){
        if(n%2) res = (res%mod * a%mod)%mod, n--;
        else a = (a%mod *a%mod)%mod, n /=2;
    }
    return res;

}

lli gcd(lli a, lli b, lli n){
    if(a==b)
    return (power(a,n, modulo) + power(b,n, modulo))%modulo;
    else{
        lli num = llabs(a-b);
        lli candidate = 1;
        for(lli i=1; i*i<=num;i++){
            if(num%i == 0)
            {
                if((power(a,n,i)+power(b,n,i))%i == 0)
                candidate = max(candidate,i);
                if((power(a,n,num/i)+power(b,n,num/i))%(num/i) == 0)
                candidate = max(candidate,num/i);
            }
        }
        return candidate%modulo;
    }
}

int main()
{
    lli t, a, b, n;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> n;
        cout << gcd(a,b,n) << endl;
    }
}