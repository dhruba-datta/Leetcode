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
        unordered_map<ListNode*, int> mp;
        ListNode* curr = headA;
        while(curr){
            mp[curr] = 1;
            curr = curr->next;
        }
        curr = headB;
        while(curr){
            if(mp[curr] == 1) return curr;
            curr = curr->next;
        }
        return NULL;
    }
};