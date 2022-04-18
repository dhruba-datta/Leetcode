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
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> a(1001, 0);
        find(root, a);
        
        struct TreeNode *ans = new TreeNode(-1);
        struct TreeNode *temp = ans;

        
        for(int i=0; i<1001; i++){
            if(a[i]==1){
                ans->right = new TreeNode(i);
                ans = ans->right;
            }
        }
        ans = temp;

        return ans->right;
    }
    void find(TreeNode* root,  vector<int> &a){
        a[root->val] = 1;
        if(root->left != NULL) find(root->left, a);
        if(root->right != NULL) find(root->right, a);
    }
};