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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        
        int ans = 1;
        
        ans += help(root->left, root->val);
        ans += help(root->right, root->val);

        return ans;
    }
    int help(TreeNode* root, int mx){
        if(!root) return 0;
        
        int count = 0;
        
        if(root->val >= mx){
            count++;
            mx = root->val;
        }
        count += help(root->left, mx);
        count += help(root->right, mx);
        
        return count;
    }
};