/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA, *temp2 = headB;
        int c1=0,c2=0;
        while(temp1 || temp2){
            if(temp1 == temp2)
                return temp1;
            
            if(temp1 == NULL)
                temp1 = headB;
            else temp1 = temp1 ->next;
            
            if(temp2 == NULL)
                temp2 = headA;
            else temp2 = temp2 -> next;
        }
        return NULL;
    }
};