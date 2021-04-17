/*
https://www.codechef.com/problems/FIRESC

Topic - DFS, Number of CC, Counting of number of nodes in a CC
*/

#include <iostream>
#include <vector>
using namespace std;
#define mod 1000000007
#define lli long long int
#define li long int

lli dfs(int start, vector<int> *adj, int *vis)
{
    vis[start] = 1;
    int count = 1;
    for (auto i = adj[start].begin(); i != adj[start].end(); i++)
        if (vis[*i] == 0)
            count += dfs(*i, adj, vis);

    return count;
}

int main()
{
    // your code goes here
    lli t;
    cin >> t;
    li n, m = 0;
    while (t--)
    {
        cin >> n >> m;
        vector<int> adj[n];
        int vis[n]={0};
        li i, j = 0;
        li total = 0;
        li permutations = 1;
        // taking data an populating adjacency matrix
        for (int k = 0; k < m; k++)
        {
            cin >> i >> j;
            adj[i - 1].push_back(j - 1);
            adj[j - 1].push_back(i - 1);
        }

        // dfs
        for (int k = 0; k < n; k++)
        {
            if (vis[k] == 0)
            {
                permutations = (permutations * dfs(k, adj, vis)) % mod;
                total++;
            }
        }

        cout << total << " " << permutations << endl;
    }
    return 0;
}
