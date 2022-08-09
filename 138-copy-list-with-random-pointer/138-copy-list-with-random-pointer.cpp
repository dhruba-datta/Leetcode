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
        Node* temp = head, *cur;
        while(temp){
            Node* node = new Node(temp->val);
            cur = temp->next;
            temp->next = node;
            node->next = cur;
            temp = cur;
        }
        
        temp = head;
        while(temp){
            if(temp->random)
                temp->next->random = temp->random->next;

            temp = temp->next->next;
        }
        temp = head;
        Node* ans = new Node(0);
        cur = ans;
        
        while(temp){
            cur->next = temp->next;
            cur = cur->next;
            temp->next = cur->next;
            temp = temp->next;
            
        }
        return ans->next;
    }
};