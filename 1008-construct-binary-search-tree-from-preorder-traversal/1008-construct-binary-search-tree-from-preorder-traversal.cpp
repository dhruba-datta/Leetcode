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
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int idx = 0;
        return help(pre, INT_MAX, idx);
    }
    
    TreeNode* help(vector<int>& pre, int mx, int &idx){
        if(idx == pre.size() || pre[idx] > mx) return NULL;
        TreeNode* root = new TreeNode(pre[idx++]);
        root->left = help(pre, root->val, idx);
        root->right = help(pre, mx, idx);
        return root;
    }
};