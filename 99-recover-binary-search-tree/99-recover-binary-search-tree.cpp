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
    TreeNode *first=NULL, *middle=NULL, *last=NULL, *prev;
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);
        inorder(root);
        
        if(last) swap(first->val, last->val);
        else swap(first->val, middle->val);       
    }
    
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        
        if(prev && root->val < prev->val){
            if(!first){
                first = prev;
                middle = root;
            }
            else
                last = root;
        }
        prev = root;
        
        inorder(root->right);
        return;
    }
};