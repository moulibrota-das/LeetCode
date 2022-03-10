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
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        int carry = 0, sum=0;
        ListNode *dummy = new ListNode(-1);
        ListNode *ptr=dummy;
        
        while(l1 && l2){
            sum = l1->val + l2->val + carry;
            ListNode *temp = new ListNode(sum%10);
            ptr->next = temp;
            ptr = ptr->next;
            carry = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1){
            sum = l1->val + carry;
            ListNode *temp = new ListNode(sum%10);
            ptr->next = temp;
            ptr = ptr->next;
            carry = sum / 10;
            l1 = l1->next;
        }
        
        while(l2){
            sum = l2->val + carry;
            ListNode *temp = new ListNode(sum%10);
            ptr->next = temp;
            ptr = ptr->next;
            carry = sum / 10;
            l2 = l2->next;
        }
        if(carry > 0){
            ListNode *temp = new ListNode(carry);
            ptr->next = temp;
        }
        
        return dummy->next;
    }
};