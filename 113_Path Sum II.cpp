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
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        dfs(root,0,targetSum); //從0開始加
        return result;
    }
private:
    void dfs(TreeNode* node,int current,int targetSum)
    {
        if (node == nullptr) return;
        path.push_back(node -> val);
        current += node->val;
        if (!node -> left && !node -> right && current == targetSum)
        {
            result.push_back(path);
        }
        dfs(node -> left,current,targetSum);
        dfs(node -> right,current,targetSum);
        path.pop_back();
    }
};
