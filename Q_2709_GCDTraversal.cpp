#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("03", "unroll-loops")
class Solution
{
public:
    vector<int> sieve(int n)
    {
        vector<bool> s(n + 1, true);
        vector<int> res;
        s[0] = s[1] = false;
        int sq = (int)(sqrt(n));
        for (int i = 2; i <= sq; i++)
            if (!s[i])
                for (int j = i * i; j <= n; j += i)
                    s[j] = false;
        for (int i = 2; i <= n; i++)
            if (s[i])
                res.push_back(i);
        return res;
    }
    void dfs(vector<vector<int>> &fac, vector<int> &vis, int *count, int i)
    {
        if (vis[i] == 1)
            *(count) += 1;
        vis[i] = 2;
        for (auto &j : fac[i])
            if (vis[j] == 1 || vis[j] == -1)
                dfs(fac, vis, count, j);
    }
    bool canTraverseAllPairs(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;
        int mxElement = *max_element(nums.begin(), nums.end());
        vector<int> primes = sieve(mxElement);
        vector<int> vis(mxElement + 1, 0);
        vector<vector<int>> fac(mxElement + 1);
        unordered_set<int> s{nums.begin(), nums.end()};
        if (s.count(1))
            return false;
        for (auto &i : s)
        {
            vis[i] = 1;
        }
        for (auto &p : primes)
        {
            if (vis[p] != 1)
                vis[p] = -1;
            for (int i = p * 2; i <= mxElement; i += p)
                if (vis[i] == 1)
                {
                    fac[p].push_back(i);
                    fac[i].push_back(p);
                }
        }
        int count = 0;
        dfs(fac, vis, &count, nums[0]);
        return count == s.size();
    }
};
int main()
{
    cout << "Hello";
}