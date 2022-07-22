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
    ListNode* partition(ListNode* head, int x) {
        ListNode* ptr = head;
        ListNode* l = new ListNode(0);
        ListNode* g = new ListNode(0);
        
        ListNode* l1 = l, *g1= g;
        ptr = head;
        
        while(ptr){
            if(ptr->val < x){
                l1->next = ptr;
                l1 = l1->next;
            }
            else if(ptr->val >= x){
                g1->next = ptr;
                g1 = g1->next;
            }
            ptr = ptr->next;
        }
        g1->next = NULL;
        l1->next = g->next;
        
        return l->next;
    }
};