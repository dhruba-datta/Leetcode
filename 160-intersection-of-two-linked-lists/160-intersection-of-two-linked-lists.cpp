/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA) return headB;
        if(!headB) return headA;
        
        ListNode* a=headA;
        ListNode* b=headB;
        
        while(a != b){
            a = (!a) ? headB : a->next;
            b = (!b) ? headA : b->next; 
        }
        return a;
    }
};