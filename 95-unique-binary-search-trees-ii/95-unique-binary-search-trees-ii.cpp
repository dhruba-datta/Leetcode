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
    vector<TreeNode*> generateTrees(int n) {
        return help(1, n);
    }
    
    vector<TreeNode*> help(int l, int r){
        if(l>r) return {NULL};
        
        vector<TreeNode*> ans;
        
        for(int root=l; root<=r; root++){
            vector<TreeNode*> left = help(l, root-1);
            vector<TreeNode*> right = help(root+1, r);
            
            for(auto x:left){
                for(auto y:right){
                    TreeNode* node = new TreeNode(root);
                    
                    node->left = x;
                    node->right = y;
                    
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
};