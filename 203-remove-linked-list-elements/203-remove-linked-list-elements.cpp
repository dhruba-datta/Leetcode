/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev=head, *curr=NULL;
        if(head) curr=head->next;
        
        while(curr){
            if(curr->val == val){
                prev->next = curr->next;
                curr = curr->next;

            }
            else{
                curr = curr->next;
                prev = prev->next;
            }
        }
        if(head && head->val == val) return head->next;
        return head;
    }
};