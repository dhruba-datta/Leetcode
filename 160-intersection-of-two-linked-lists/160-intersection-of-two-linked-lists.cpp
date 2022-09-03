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
        unordered_set<ListNode*> st;
        ListNode *x = headA;
        while(x){
            st.insert(x);
            x = x->next;
        }
        x = headB;
        while(x){
            if(st.find(x) != st.end())
                return x;
            x = x->next;
        }
        
        return NULL;
    }
};