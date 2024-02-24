#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};
class Solution
{
public:
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        queue<TreeNode *> q, lastDepth;
        q.push(root);
        unordered_map<TreeNode *, TreeNode *> parentOf;
        while (!q.empty())
        {
            queue<TreeNode *> temp;
            lastDepth = q;
            while (!q.empty())
            {
                TreeNode *x = q.front();
                q.pop();
                if (x->left)
                {
                    temp.push(x->left);
                    parentOf[x->left] = x;
                }
                if (x->right)
                {
                    temp.push(x->right);
                    parentOf[x->right] = x;
                }
            }
            q = temp;
        }
        while (lastDepth.size() != 1)
        {
            unordered_set<TreeNode *> s;
            queue<TreeNode *> temp;
            while (!lastDepth.empty())
            {
                TreeNode *x = lastDepth.front();
                TreeNode *parent = parentOf[x];
                lastDepth.pop();
                if (s.find(parent) == s.end())
                {
                    temp.push(parent);
                    s.insert(parent);
                }
            }
            lastDepth = temp;
        }
        return lastDepth.front();
    }
};