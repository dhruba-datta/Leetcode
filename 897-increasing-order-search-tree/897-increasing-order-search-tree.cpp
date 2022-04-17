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
    TreeNode* tree = new TreeNode(0); // make new node and initialize with 0 value
    TreeNode *h = tree; // another node pointing to the head of new node
    
    void inorder(TreeNode* root){
         if(root==NULL){
            return;
        }
        
        inorder(root->left);
        tree->right= new TreeNode(root->val);  // make new node with root value 
        tree->left=NULL;  
        tree=tree->right;  // move ahead in right direction
        
       inorder(root->right);
       
    }
    
    TreeNode* increasingBST(TreeNode* root) {       
        
        inorder(root);
        return h->right; // move in right to skip the initial 0 value
    }
};