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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        unordered_map<int,int> mp;
        
        for(int i=0; i<post.size(); i++)
            mp[post[i]] = i;
        
        int index = 0;
        return help(mp, pre, index);
    }
    
    TreeNode* help(unordered_map<int,int> &mp, vector<int>& pre, int &index){
        int curr = pre[index];
        TreeNode* root = new TreeNode(curr);
        index++;
        if(index<pre.size()  && mp[pre[index]] < mp[curr])
            root->left = help(mp, pre, index);
        else return root;
        
        if(index<pre.size()  && mp[pre[index]] < mp[curr])
            root->right = help(mp, pre, index);
    
        return root;
        
    }
};