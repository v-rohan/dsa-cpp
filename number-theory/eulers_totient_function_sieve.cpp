#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define mod 1000000007
#define lli long long int
#define li long int
#define REP(i, n) for (int i = 1; i <= n; i++)
#define vi vector<int>
int phi[1000001];

void buildtotient()
{
    for (int i = 2; i * i <= 1000000; i++)
    {
        if (phi[i] == 0)
            for (int j = i; j <= 1000000; j += i)
                if (phi[j] == 0)
                    phi[j] = j * (i - 1) / i;
                else
                    phi[j] = phi[j] * (i - 1) / i;
    }
}

int main()
{
    buildtotient();
    int t,n;
    cin >> t;
    while(t--){
        cin>> n;
        cout << phi[n] << endl;
    }
}