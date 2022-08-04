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
    long long pathSum(TreeNode* root, long long sum) {
        if(!root) return 0;
        return pathSum(root->left, sum) + pathSum(root->right, sum) + help(root, sum);
    }
    long long help(TreeNode* root, long long sum){
        if(!root) return 0;
        long long count = 0;
        if(root->val == sum) count++;
        count += help(root->left, sum-root->val);
        count += help(root->right, sum-root->val);
        return count;
    }
};