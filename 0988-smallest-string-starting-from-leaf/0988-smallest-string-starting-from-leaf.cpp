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
    string smallestString;
    
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return smallestString;
    }

    void dfs(TreeNode* root, string currentString) {
        if (!root) return;
        currentString = char(root->val + 'a') + currentString; 
        if (!root->left && !root->right){ 
            if (smallestString == "" || smallestString > currentString) { 
                smallestString = currentString;
            }
        }
        if (root->left) dfs(root->left, currentString);
        if (root->right) dfs(root->right, currentString);
    }
};