/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
      if (root) {
      if (root->left && root->right)
        root->left->next = root->right;
      
      Node * edge = root->right;
      if (!edge)
        edge = root->left;
      if (edge) {
        Node * next = root->next;
        while (next) {
          if (next->left) {
            edge->next = next->left;
            break;
          }
          else if (next->right) {
            edge->next = next->right;
            break;
          }
          else
            next = next->next;
        }
      }
      connect(root->right);
      connect(root->left);
    }
    return root;
  }
};
