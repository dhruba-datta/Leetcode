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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 && root2){
            int a = (!root1) ? 0 : root1->val;
            int b = (!root2) ? 0 : root2->val;

            TreeNode* ans = new TreeNode(a+b);

            ans->left = mergeTrees(root1->left, root2->left);
            ans->right = mergeTrees(root1->right, root2->right);

            return ans;
        }
        else
            return root1 ? root1 : root2;
    }
};