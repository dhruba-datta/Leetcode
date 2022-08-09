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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=0;
        ListNode *temp = head;
        
        while(temp){
            l++;
            temp = temp->next;
        }
        if(l==n) return head->next;
        
        int count = l-n;
        l = 0;
        temp = head;
        while(temp){
            if(l == count-1){
                temp->next = temp->next->next;
            }l++;
            temp = temp->next;
        }
        return head;
    }
};