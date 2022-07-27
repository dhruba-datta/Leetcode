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
    int mn = INT_MAX;
    TreeNode* prev = NULL;
    
    int getMinimumDifference(TreeNode* root) {
        if(root->left) getMinimumDifference(root->left);
        
        if(prev) mn = min(mn, abs(root->val - prev->val));

        prev = root;
                
        if(root->right) getMinimumDifference(root->right);
        
        return mn;
    }
};