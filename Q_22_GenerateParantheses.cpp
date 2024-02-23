#include <bits/stdc++.h>
using namespace std;
void helper(vector<string> &result, string soFar, int open, int close)
{
    if (open == 0 && close == 0)
    {
        result.push_back(soFar);
        return;
    }
    if (open > 0)
        helper(result, soFar + "(", open - 1, close);
    if (open < close)
        helper(result, soFar + ")", open, close - 1);
}
vector<string> generateParantheses(int n)
{
    vector<string> result;
    helper(result, "", n, n);
    return result;
}
int main()
{
    return 0;
}