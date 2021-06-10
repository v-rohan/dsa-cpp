#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        pair<int, int> max = {INT_MIN, -1};
        pair<int, int> min = {INT_MAX, -1};
        for (int i = 0; i < n; i++)
        {
            if (max.first < arr[i])
                max.first = arr[i], max.second = i;
            if (min.first > arr[i])
                min.first = arr[i], min.second = i;
        }
        int dif = abs(min.second - max.second);
        int minl = -1;
        int minr = n + 1;
        if (min.second < max.second)
        {
            minl = min.second + 1;
            minr = max.second;
        }
        else
        {
            minl = max.second + 1;
            minr = min.second;
        }
        int steps = (minl < (n - minr) ? minl : (n - minr)) + dif;
        steps = std::min(steps, (minl + n - minr));
        cout << steps << endl;
    }
}
