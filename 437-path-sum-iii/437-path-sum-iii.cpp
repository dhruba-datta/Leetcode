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
    long long count = 0;
    long long pathSum(TreeNode* root, long long sum) {
        if(root){
            help(root, sum);
            pathSum(root->left, sum);
            pathSum(root->right, sum);
        }
        return count;
    }
    void help(TreeNode* root, long long sum){
        if(!root) return;
        if(root->val == sum) count++;
        help(root->left, sum-root->val);
        help(root->right, sum-root->val);
        return;
    }
};