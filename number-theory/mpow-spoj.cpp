/*
https://www.spoj.com/problems/MPOW/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define mod 1000000007
#define lli long long int
#define li long int
#define vi vector<int>

lli matrix[51][51];
void multiplyMatrices(lli m1[][51], lli m2[][51], int dim)
{
    lli res[dim + 1][dim + 1];
    for (int i = 1; i <= dim; i++)
        for (int j = 1; j <= dim; j++)
        {
            res[i][j] = 0;
            for (int k = 1; k <= dim; k++)
            {
                res[i][j] = (res[i][j] % mod + ((m1[i][k] % mod) * (m2[k][j] % mod) % mod)) % mod;
            }
        }

    for (int i = 1; i <= dim; i++)
        for (int j = 1; j <= dim; j++)
        {
            m1[i][j] = res[i][j];
        }
}
void printMatrix(lli matrx[][51], int dim)
{
    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
        {
            cout << matrx[i][j] << " ";
        }
        cout << endl;
    }
}
void raisePower(lli matrx[][51], int dim, int power)
{
    lli identity[51][51];
    for (int i = 1; i <= dim; i++)
    for(int j=1;j<=dim;j++)
    if(i==j)
        identity[i][j] = 1;
    else identity[i][j] =0;

    //cout << "Identitiy check\n";
    //printMatrix(identity, dim);

    while (power)
    {
        //cout << "state at power: " << power << endl;
        if (power % 2)
            multiplyMatrices(identity, matrx, dim), power--;

        else
            multiplyMatrices(matrx, matrx, dim), power /= 2;
        //cout << "Identity : \n", printMatrix(identity, dim);
        //cout << "Matrx : \n", printMatrix(matrx, dim);
    }

    for (int i = 1; i <= dim; i++)
        for (int j = 1; j <= dim; j++)
            matrx[i][j] = identity[i][j];
}

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
                cin >> matrix[i][j];
        raisePower(matrix, m, n);
        printMatrix(matrix, m);
    }
}