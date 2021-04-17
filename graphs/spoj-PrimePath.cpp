/*
https://www.spoj.com/problems/PPATH/
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
vector<int> primes;

bool isValid(int i, int j)
{
    int count = 0;
    while (i)
    {
        if (i % 10 != j % 10)
        {
            count++;
        }

        i /= 10;
        j /= 10;
    }

    if (count == 1)
        return true;
    return false;
}

bool isPrime(int a)
{
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

void buildgraph(vector<int> (&adj)[10000])
{
    for (int i = 1000; i <= 9999; i++)
        if (isPrime(i))
            primes.push_back(i);

    for (int i = 0; i < primes.size(); i++)
        for (int j = i + 1; j < primes.size(); j++)
            if (isValid(primes[i], primes[j]))
                adj[primes[i]].push_back(primes[j]), adj[primes[j]].push_back(primes[i]);

    primes.clear();
}

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
        vector<int> adj[10000];
        int dis[10000];
        int vis[10000] = {0};
        for (int i = 0; i <= 9999; i++)
            dis[i] = -1;
        li i, j = 0;
        buildgraph(adj);
        // taking data an populating adjacency matrix
        cin >> i >> j;
        bfs(i, adj, vis, dis);
        if (dis[j] == -1)
            cout << "Impossible" << endl;
        else
            cout << dis[j] << endl;
    }
}