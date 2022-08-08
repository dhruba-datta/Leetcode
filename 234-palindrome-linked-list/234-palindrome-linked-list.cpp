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
    bool isPalindrome(ListNode* head) {
        vector<int> temp;
        while(head){
            temp.push_back(head->val);
            head = head->next;
        }
        int n = temp.size();
        
        for(int i=0; i<n/2; i++){
            if(temp[i] != temp[n-i-1]) return false;
        }
        return true;
    }
};