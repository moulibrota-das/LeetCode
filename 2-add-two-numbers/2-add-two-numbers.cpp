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
        
        while(l1 || l2){
            sum = (l1==NULL ? 0:l1->val) + (l2==NULL ? 0:l2->val) + carry;
            ptr->next = new ListNode(sum%10);
            ptr = ptr->next;
            carry = sum / 10;
            if(l1)  l1 = l1->next;
            if(l2)  l2 = l2->next;
        }
        
        if(carry > 0){
            ptr->next = new ListNode(carry);
        }
        
        return dummy->next;
    }
};