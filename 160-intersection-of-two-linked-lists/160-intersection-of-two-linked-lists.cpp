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
        if(!headA || !headB) return NULL;
        ListNode *d1= headA, *d2= headB;
        
        while(d1 != d2){
            d1 = !d1 ? headB : d1->next;
            d2 = !d2 ? headA : d2->next;
        }
        return d1;
    }
};