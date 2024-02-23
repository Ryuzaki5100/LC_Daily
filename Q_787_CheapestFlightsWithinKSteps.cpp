#include <bits/stdc++.h>
using namespace std;
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<vector<int>> adjMat(n, vector<int>(n, 0));
    for (auto i : flights)
        adjMat[i[0]][i[1]] = i[2];
    queue<tuple<int, int, int>> q;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    q.push({src, 0, -1});
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        int node = get<0>(x), cost = get<1>(x), steps = get<2>(x);
        if (steps < k)
            for (int i = 0; i < n; i++)
                if (adjMat[node][i] != 0 && dist[i] > cost + adjMat[node][i])
                    q.push({i, dist[i] = cost + adjMat[node][i], steps + 1});
    }
    if (dist[dst] == INT_MAX)
        return -1;
    return dist[dst];
}
int main()
{
    return 0;
}
