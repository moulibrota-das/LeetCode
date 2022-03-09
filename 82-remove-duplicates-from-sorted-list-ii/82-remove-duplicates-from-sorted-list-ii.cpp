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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *ptr = dummy, *curr = ptr->next;
        
        
        while(ptr->next){
            curr = ptr->next;
            int count = 0;
            while(curr->next && curr->val == curr->next->val){
                curr = curr->next;
                count++;
            }
            if(count>0) ptr->next = curr->next;
            else ptr=ptr->next;
        }
        
        return dummy->next;
    }
};