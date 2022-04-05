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
    ListNode* swapNodes(ListNode* head, int k) {        
        ListNode *kthNode = NULL, *kthNodeFromEnd = NULL, *iter = head;
        int len = 0, idx = 0;
        while(iter)
            iter = iter -> next, len++;
        iter = head;
        while(iter){
            if(idx == k - 1) kthNode = iter;
            if(idx == len - k) kthNodeFromEnd = iter;
            if(kthNode && kthNodeFromEnd) break;
            iter = iter -> next, idx++;
        }   
        swap(kthNode -> val, kthNodeFromEnd -> val);
        return head;
    }
};