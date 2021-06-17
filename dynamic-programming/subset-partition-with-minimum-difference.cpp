#include <bits/stdc++.h>
using namespace std;
int t[1000][1000];
int main()
{
    int size;
    cin >> size;
    int sum = 0;
    int dif;
    cin >> dif;
    vector<int> wt(size);
    while (size)
    {
        cin >> wt[wt.size() - size];
        sum += wt[wt.size() - size--];
    }
    int sum_to_be_searched = (sum + dif) / 2;

    for (int i = 0, j = 0; j <= sum_to_be_searched; j++)
        t[i][j] = 0;
    for (int j = 0, i = 0; i <= wt.size(); i++)
        t[i][j] = 1;
    for (int i = 1; i <= wt.size(); i++)
        for (int j = 1; j <= sum_to_be_searched; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j] + t[i - 1][j - wt[i - 1]];
            }
            else
                t[i][j] = t[i - 1][j];
        }
    cout << t[wt.size()][sum_to_be_searched] << endl;
}