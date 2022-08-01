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
    bool isValidBST(TreeNode* root) {
        return isValid(root, NULL, NULL);
    }
    
    bool isValid(TreeNode* root, int* lower, int* upper){
        if(!root)
            return true;

        if(upper && root -> val >= *upper)
            return false;
        if(lower && root -> val <= *lower)
            return false;
        
        return isValid(root -> left, lower, &(root -> val)) && isValid(root -> right, &(root -> val), upper);
    }
};