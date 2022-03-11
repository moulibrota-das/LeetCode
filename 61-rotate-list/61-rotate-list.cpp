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
        if(head == NULL || head->next == NULL) return head;
        
        int n = 1;
        ListNode *ptr = head;
        while(ptr->next){
            n++;
            ptr = ptr->next;
        }
        ptr->next = head;
        
        k = k%n;
        ListNode *dummy = new ListNode(0);
        ptr = head;
        
        for(int i = 1; i<=(n-k-1); i++){
            ptr = ptr->next;
        }
        dummy->next = ptr->next;
        ptr->next = NULL;
        
        return dummy->next;
    }
};