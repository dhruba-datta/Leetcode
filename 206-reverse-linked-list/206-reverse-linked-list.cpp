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
    ListNode* reverseList(ListNode* head) {
        return help(NULL, head);
    }
    
    ListNode* help(ListNode* prev, ListNode* head){
        if(!head) return prev;
        
        ListNode* temp = head->next;
        head->next = prev;
        
        return help(head, temp);
    }
};