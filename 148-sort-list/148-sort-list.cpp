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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *left, *right, *fast=head->next, *slow=head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = slow->next;
        slow->next = NULL;
        
        left = sortList(head); 
        right = sortList(fast);
        
        return merge(left, right);
    }
    
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode *temp = new ListNode(0), *ans = temp;
        
        while(left && right){
            if(left->val < right->val){
                temp->next = left;
                left = left->next;
            }
            else{
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        if(left) temp->next = left;
        if(right) temp->next = right;
        
        return ans->next;
    }
};