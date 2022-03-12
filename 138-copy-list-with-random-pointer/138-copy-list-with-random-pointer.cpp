/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        if (m[head]) return m[head];
        m[head] = new Node(head->val);
        m[head]->next = copyRandomList(head->next);
        m[head]->random = copyRandomList(head->random);
        return m[head];
    }
private:
    unordered_map<Node*, Node*> m;
};