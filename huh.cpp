#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    unordered_set<string> x = {"1", "2", "3", "4", "5", "6", "7",
                               "8", "9", "10", "11", "12", "13", "14",
                               "15", "16", "17", "18", "19", "20", "21",
                               "22", "23", "24", "25", "26"};
    int numDecodings(string s)
    {
        if (s[0] == '0')
            return 0;
        int n = s.length(), one, two;
        vector<int> dp(n, 0);
        dp[0] = 1;
        one = x.find(s.substr(1, 1)) != x.end();
        two = x.find(s.substr(0, 2)) != x.end();
        dp[1] = one + two;
        for (int i = 2; i < n; i++)
        {
            int two = x.find(s.substr(i - 1, 2)) != x.end(),
                one = x.find(s.substr(i, 1)) != x.end(),
                sumTwo = two == 0 ? 0 : dp[i - 2],
                sumOne = one == 0 ? 0 : dp[i - 1];
            dp[i] = sumOne + sumTwo;
        }
        return dp[n - 1];
    }
};
int main()
{
    string temp = "";
    cin >> temp;
    Solution s;
    // cout << s.numDecodings(temp);
    cout << to_string('a');
}