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
    ListNode* rotateRight(ListNode* head, int k) {
       
        ListNode *temp = head, *ptr = head;
        
		// if  list is empty return NULL
        if(head == NULL)
            return NULL;
			
        // if  list contain 1 node return NULL
        if(head -> next == NULL)
            return head;
        
        int cnt = 1;
        
		// counting nodes in list
        while(temp->next != NULL)
        {
            temp = temp -> next;
            cnt++;
        }
		
		// mod of k with cnt to find the minimum no of rotations.
        k = k % cnt;
        
        while(k--)
        {
            while(temp->next != NULL)
                temp = temp -> next;
        
            temp -> next = head;           //making it a circular linked list
			
			// making last node the new head
            head = temp;
            ptr = temp;
			
			// moving list values one by one
            while(temp -> next != head)
            {
                temp = temp -> next;
            }
            
			// adding NULL at end of list
            temp -> next = NULL;
			
            temp = ptr;
            
        }
        return head;
    }
};