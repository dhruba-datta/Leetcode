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
    int sum = 0;
    bool flag = false;
    int sumOfLeftLeaves(TreeNode* root) {
        if(root->left){
            flag = true;
            sumOfLeftLeaves(root->left);
        }
        
        if(flag == true && root->left == NULL && root->right == NULL) sum += root->val;
        
        if(root->right){
            flag = false;
            sumOfLeftLeaves(root->right);
        }
        return sum;
        
    }
};