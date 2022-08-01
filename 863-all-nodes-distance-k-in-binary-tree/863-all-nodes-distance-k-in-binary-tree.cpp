/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        find_parent(root, parent);
        
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int level = 0;
        
        while(!q.empty()){
            int size = q.size();
            if(level++ == k) break;
            
            for(int i=0; i<size; i++){
                auto temp = q.front();
                q.pop();
                
                if(temp->left && !vis[temp->left]){
                    q.push(temp->left);
                    vis[temp->left] = true;
                }
                
                if(temp->right && !vis[temp->right]){
                    q.push(temp->right);
                    vis[temp->right] = true;
                }
                
                if(parent[temp] && !vis[parent[temp]]){
                    q.push(parent[temp]);
                    vis[parent[temp]] = true;
                }
            }
            
        }
        vector<int> ans;
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
    void find_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        queue<TreeNode*> curr;
        curr.push(root);
        while(!curr.empty()){
            auto temp = curr.front();
            curr.pop();
            if(temp->left){
                parent[temp->left] = temp;
                curr.push(temp->left);
            }
            if(temp->right){
                parent[temp->right] = temp;
                curr.push(temp->right);
            }
        }
    }
};