/*
https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/

Topics - BFS
*/

// Write your code here
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define mod 1000000007
#define lli long long int
#define li long int

queue<int> qu;

void bfs(int start, vector<int> *adj, int *vis, int *dis)
{
    vis[start] = 1;
    dis[start] = 0;
    qu.push(start);
    while (!qu.empty())
    {
        int front = qu.front();
        for (auto it = adj[front].begin(); it != adj[front].end(); it++)
            if (vis[*it] == 0)
                qu.push(*it), dis[*it] = dis[front] + 1, vis[*it] = 1;
        qu.pop();
    }
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
        int dis[n] = {0};
        int vis[n] = {0};
        li i, j = 0;
        // taking data an populating adjacency matrix
        for (int k = 0; k < m; k++)
        {
            cin >> i >> j;
            adj[i - 1].push_back(j - 1);
            adj[j - 1].push_back(i - 1);
        }

        bfs(0, adj, vis, dis);
        cout << dis[n-1] << endl;
    }
}