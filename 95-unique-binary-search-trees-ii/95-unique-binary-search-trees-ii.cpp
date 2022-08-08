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
            for(auto left : help(l, root-1)){
                for(auto right : help(root+1, r)){
                    ans.push_back(new TreeNode(root, left, right));
                }
            }
        }
        return ans;
    }
};