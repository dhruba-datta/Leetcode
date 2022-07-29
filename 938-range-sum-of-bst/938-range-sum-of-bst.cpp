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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()){
            TreeNode* top = st.top();
            st.pop();
            if(top->val >= low && top->val <= high) ans += top->val;
            if(top->val < high){
                if(top->right) st.push(top->right);
            }
            if(top->val > low){
                if(top->left) st.push(top->left);
            }
        }
        return ans;
    }
};