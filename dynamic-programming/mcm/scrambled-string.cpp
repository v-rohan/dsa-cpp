#include <bits/stdc++.h>
using namespace std;
unordered_map<string, bool> mp;
bool scramble(string x, string y)
{
    if (x == y)
        return true;
    if (x.length() <= 1)
        return false;
    if (mp.find(x + " " + y) != mp.end())
        return mp[x + " " + y];
    for (int i = 1; i < x.length(); i++)
    {
        bool ul = scramble(x.substr(0, i), y.substr(0, i));
        bool ur = scramble(x.substr(i), y.substr(i));
        bool fl = scramble(x.substr(0, i), y.substr(x.length() - i, i));
        bool fr = scramble(x.substr(i, x.length() - i), y.substr(0, x.length() - i));
        if ((ul && ur) || (fl && fr))
            return mp[x + " " + y] = true;
    }
    return mp[x + " " + y] = false;
}
int main()
{
    string x, y;
    cin >> x >> y;
    string arr[] = {"false", "true"};
    cout << arr[scramble(x, y)] << endl;
}