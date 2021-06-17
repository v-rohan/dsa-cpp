#include <bits/stdc++.h>
using namespace std;
bool t[1000][1000];
int main()
{
    int size;
    cin >> size;
    int sum;
    cin >> sum;
    vector<int> wt(size);
    while (size--)
    {
        cin >> wt[wt.size() - size];
    }
    for (int i = 0, j = 0; j <= sum; j++)
        t[i][j] = false;
    for (int j = 0, i = 0; i <= wt.size(); i++)
        t[i][j] = true;

    for (int i = 1; i <= wt.size(); i++)
        for (int j = 1; j <= sum; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - wt[i - 1]] || t[i - 1][j];
            }
            else
                t[i][j] = t[i - 1][j];
        }
    cout << t[wt.size()][sum] << endl;
}