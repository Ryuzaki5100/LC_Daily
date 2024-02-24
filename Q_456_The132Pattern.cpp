#include <bits/stdc++.h>
using namespace std;
bool find132Pattern(vector<int> &nums)
{
    // We try to find the second maximum element in the maxStack and keep it in this variable
    int maximizeThirdNumIn132 = INT_MIN;
    stack<int> s;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        // If the second maximum element in the maxStack is greater than nums[i], this means it's 132 pattern, i.e, 2 (second maximum element in the stack) > 1 (nums[i]) condition
        if (maximizeThirdNumIn132 > nums[i])
            return true;
        // keep popping as long as the array element is greater than the stack top (to maintain maxStack condition)
        // and keep updating the maxthirdnNum variable so keep track of the second largest element at every pop
        while (!s.empty() && s.top() < nums[i])
        {
            maximizeThirdNumIn132 = s.top();
            s.pop();
        }
        s.push(nums[i]);
    }
    return false;
}
int main()
{
    return 0;
}