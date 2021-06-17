#include <bits/stdc++.h>
using namespace std;
int main()
{
    int size;
    cin >> size;
    int t[9][9];
    vector<int> wt(size);
    while (size)
    {
        cin >> wt[wt.size() - size--];
    }
    size = wt.size();
    for (int i = 0, j = 0; j <= size; j++)
        t[i][j] = 0;
    for (int i = 0, j = 0; i <= size; i++)
        t[i][j] = 0;
    for (int i = 1; i <= size; i++)
        for (int j = 1; j <= size; j++)
        {
            if (i <= j)
                t[i][j] = max(t[i - 1][j], wt[i - 1] + t[i][j - i]);
            else
                t[i][j] = t[i - 1][j];
        }
    cout << t[size][size] << endl;
}