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
    TreeNode* ans;
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* temp = new TreeNode(0);
        ans = temp;
        inorder(root);
        return temp->right;
    }
    
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        root->left = NULL;
        ans->right = root;
        ans = ans->right;
        inorder(root->right);
    }
};