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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1, NULL);
        l2 = reverse(l2, NULL);
        
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        int c = 0;
        
        while(l1 || l2 || c){
            int sum = 0;
            
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += c;
            c = sum/10;
            ListNode* next = new ListNode(sum%10);
            temp->next = next;
            temp = temp->next;
        }
        return reverse(head->next, NULL);
    }
    ListNode* reverse(ListNode* head, ListNode* prev){
        if(!head) return prev;
        ListNode* temp = head->next;
        head->next = prev;
        return reverse(temp, head);
    }
};