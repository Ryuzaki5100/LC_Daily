#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool helper(string s, int o, int i)
    {
        if (i == s.length())
            return o == 0;
        if (o < 0)
            return false;
        if (s[i] == '(')
            return helper(s, o + 1, i + 1);
        if (s[i] == ')')
            return helper(s, o - 1, i + 1);
        return helper(s, o, i + 1) || helper(s, o + 1, i + 1) ||
               helper(s, o - 1, i + 1);
    }
    bool checkValidString(string s)
    {
        int n = s.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 2, false));
        dp[n][1] = true;
        for (int i = n - 1; i >= 0; i--)
            for (int o = n; o >= 1; o--)
                dp[i][o] = s[i] == '(' ? dp[i + 1][o + 1] : (s[i] == ')' ? dp[i + 1][o - 1] : dp[i + 1][o] || dp[i + 1][o + 1] || dp[i + 1][o - 1]);
        return dp[0][1];
    }
};
int main()
{
}