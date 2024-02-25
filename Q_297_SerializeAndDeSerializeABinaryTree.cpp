#include <bits/stdc++.h>
using namespace std;
//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};
class Codec
{
public:
    vector<string> splitSpaces(string s)
    {
        vector<string> res;
        for (int i = 0, j = 0; j < s.length(); j++)
        {
            if (s[j] == ' ')
            {
                res.push_back(s.substr(i, j - i));
                i = j + 1;
            }
        }
        return res;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
            return "";
        string result = to_string(root->val) + " ";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *x = q.front();
            q.pop();
            if (x->left == NULL)
                result += "_ ";
            else
            {
                q.push(x->left);
                result += to_string(x->left->val) + " ";
            }
            if (x->right == NULL)
                result += "_ ";
            else
            {
                q.push(x->right);
                result += to_string(x->right->val) + " ";
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data == "")
            return NULL;
        vector<string> nodes = splitSpaces(data);
        TreeNode *root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode *> q;
        q.push(root);
        for (int i = 1; i < nodes.size(); i += 2)
        {
            TreeNode *parent = q.front();
            q.pop();
            if (nodes[i] != "_")
            {
                parent->left = new TreeNode(stoi(nodes[i]));
                q.push(parent->left);
            }
            if (nodes[i + 1] != "_")
            {
                parent->right = new TreeNode(stoi(nodes[i + 1]));
                q.push(parent->right);
            }
        }
        return root;
    }
};