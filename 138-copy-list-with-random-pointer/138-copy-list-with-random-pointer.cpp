/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node *ptr = head;
        while(ptr){
            Node *temp = new Node(ptr->val);
            temp->next = ptr->next;
            ptr->next = temp;
            ptr=temp->next;
        }
        
        ptr = head;
        while(ptr){
            if(ptr->random)
                ptr->next->random = ptr->random->next;
            ptr = ptr->next->next;
        }
        
        Node *dummy = new Node(0);
        ptr = dummy;
        Node *it = head;
        
        while(it){
            Node *temp = it->next->next;
            ptr->next  = it->next;
            it->next = temp;
            it = temp;
            ptr = ptr->next;
        }
        
        return dummy->next;
        
    }
};