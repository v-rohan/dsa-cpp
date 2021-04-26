#include <bits/stdc++.h>
using namespace std;

void bfs(int start, vector<int> nums, vector<vector<int>> adj, vector<int> &dist, vector<int> &prev)
{
    vector<int> vis(100000);
    std::fill(vis.begin(), vis.end(), 0);
    queue<int> bfsorder;
    bfsorder.push(start);
    while (!bfsorder.empty())
    {
        int a = bfsorder.front();
        bfsorder.pop();
        vis[a] = 1;
        for (auto it = adj[a].begin(); it != adj[a].end(); it++)
        {
            if (vis[*it] == 0)
            {
                vis[*it] = 1;
                prev[*it] = a;
                bfsorder.push(*it);
                if (__gcd(nums[start], nums[*it]) == 1)
                    dist.push_back(*it);
                if (*it == 0)
                    return;
            }
        }
    }

    return;
}
vector<int> getCoprimes(vector<int> &nums, vector<vector<int>> &edges)
{
    vector<int> solu(nums.size());
    std::fill(solu.begin(), solu.end(), -1);
    vector<vector<int>> anMatrix(nums.size());
    vector<int> dist;
    vector<int> prev(nums.size());
    vector<int> done(nums.size());
    std::fill(done.begin(), done.end(), 0);
    for (int i = 0; i < nums.size() - 1; i++)
    {
        anMatrix[(edges[i])[1]].push_back(edges[i][0]);
        anMatrix[(edges[i])[0]].push_back(edges[i][1]);
    }
    vector<int> truepath;
    //   cout << "hi" << endl;
    int count = 0;

    for (int itrrr = 0; itrrr < nums.size(); itrrr++)
    {
        if(done[itrrr])continue;
        int find = 0;
       // cout << "itrrr    " << itrrr << "\n";
        done[itrrr] = 1;
        bfs(itrrr, nums, anMatrix, dist, prev);
        count++;
        while (find != itrrr)
        {
            if (std::find(dist.begin(), dist.end(), find) != dist.end())
                solu[itrrr] = find;
            truepath.push_back(find);
            find = prev[find];
        }
        //   cout << "itrrr    "<<itrrr<<"\n";
        for (int i = truepath.size() - 1; i > 0; i--)
        {
            for (int j = i - 1; j >= 0; j--)
                if (__gcd(nums[truepath[i]], nums[truepath[j]]) == 1)
                {
                    solu[truepath[i]] = truepath[j];
                    break;
                }
            done[truepath[i]] = 1;
        }
        prev.clear();
        truepath.clear();
        dist.clear();
    }

    // cout << "cant el barca" << endl;


       // cout << count << "   " << endl;
    return solu;
}

int main()
{
    vector<int> nums = {9, 16, 30, 23, 33, 35, 9, 47, 39, 46, 16, 38, 5, 49, 21, 44, 17, 1, 6, 37, 49, 15, 23, 46, 38, 9, 27, 3, 24, 1, 14, 17, 12, 23, 43, 38, 12, 4, 8, 17, 11, 18, 26, 22, 49, 14, 9};
    vector<vector<int>> edges = {{17, 0}, {30, 17}, {41, 30}, {10, 30}, {13, 10}, {7, 13}, {6, 7}, {45, 10}, {2, 10}, {14, 2}, {40, 14}, {28, 40}, {29, 40}, {8, 29}, {15, 29}, {26, 15}, {23, 40}, {19, 23}, {34, 19}, {18, 23}, {42, 18}, {5, 42}, {32, 5}, {16, 32}, {35, 14}, {25, 35}, {43, 25}, {3, 43}, {36, 25}, {38, 36}, {27, 38}, {24, 36}, {31, 24}, {11, 31}, {39, 24}, {12, 39}, {20, 12}, {22, 12}, {21, 39}, {1, 21}, {33, 1}, {37, 1}, {44, 37}, {9, 44}, {46, 2}, {4, 46}};
    //cout << "fififi\n";
    vector<int> arr = getCoprimes(nums, edges);
    //  cout << " nannaa";
    for (int i = 0; i < nums.size(); i++)
        cout << arr[i] << " ";
}