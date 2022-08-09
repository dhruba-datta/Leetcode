/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head) help(head);
        return head;
    }
    
    Node* help(Node* head){
        Node *curr=head, *next=head, *tail=head;
        
        while(curr){
            next = curr->next;
            if(curr->child){
                Node* temp = help(curr->child); //will return tail
                temp->next = curr->next;
                if(curr->next) curr->next->prev = temp;
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = NULL;
                curr = tail;
            }
            else
                curr = curr->next;
            if(curr) tail = curr;
        }
        
        return tail;
    }
        
};