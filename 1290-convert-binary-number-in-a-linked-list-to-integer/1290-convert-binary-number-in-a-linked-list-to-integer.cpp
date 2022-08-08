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
    int getDecimalValue(ListNode* head) {
        vector<int> temp;
        
        while(head){
            temp.push_back(head->val);
            head = head->next;
        }
        
        int size = temp.size();
        int ans = 0;
        for(int i=0; i<size; i++){
            ans += temp[i]*pow(2, size-i-1);
        }
        
        return ans;
    }
};