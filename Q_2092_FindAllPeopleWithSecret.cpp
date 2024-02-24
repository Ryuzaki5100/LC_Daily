#include <bits/stdc++.h>
using namespace std;
vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
{
    vector<bool> peopleWhoKnow(n, false);
    peopleWhoKnow[0] = true, peopleWhoKnow[firstPerson] = true;
    map<int, vector<pair<int, int>>> mp;
    for (auto &i : meetings)
        mp[i[2]].push_back({i[0], i[1]});
    for (auto &[t, mat] : mp)
    {
        unordered_map<int, vector<int>> adjacencyList;
        unordered_set<int> currentKnow;
        for (auto &[a, b] : mat)
        {
            adjacencyList[a].push_back(b);
            adjacencyList[b].push_back(a);
            if (peopleWhoKnow[a])
                currentKnow.insert(a);
            if (peopleWhoKnow[b])
                currentKnow.insert(b);
        }
        queue<int> q;
        for (auto &i : currentKnow)
            q.push(i);
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (auto &i : adjacencyList[x])
                if (!peopleWhoKnow[i])
                {
                    peopleWhoKnow[i] = true;
                    q.push(i);
                }
        }
    }
    vector<int> result;
    for (int i = 0; i < n; i++)
        if (peopleWhoKnow[i])
            result.push_back(i);
    return {};
}
int main()
{
    return 0;
}