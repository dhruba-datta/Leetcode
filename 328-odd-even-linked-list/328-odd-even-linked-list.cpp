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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* left= new ListNode(0);
        ListNode* right= new ListNode(0);
        ListNode* temp = head, *dummy = right;
        int count = 0;
        
        while(temp){
            if(count%2 == 0){
                left->next = temp;
                left = left->next;
            }
            else{
                right->next = temp;
                right = right->next;
            }
            temp = temp->next;
            count++;
        }
        left->next = dummy->next;
        right->next = NULL;
        return head;
    }
};