/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int max=0;
    int sum=0;
    int deepestLeavesSum(TreeNode* root)
    {
        dfs(root,0);
        return sum;
    }
private:
    void dfs(TreeNode* node,int depth)
    {
        if (node == nullptr)return;
        if (!node->left && !node->right)
        {
            if (depth > max)
            {
                max = depth;
                sum = node->val;
            }
            else if (depth == max)
            {
                sum += node->val;
            }
            return;
        }
        dfs(node->left,depth+1);
        dfs(node->right,depth+1);
    }
};