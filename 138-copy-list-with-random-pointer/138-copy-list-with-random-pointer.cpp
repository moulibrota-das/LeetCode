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
        map<Node*, Node*> map;
        
        Node *ptr = head;
        while(ptr){
            Node *temp = new Node(ptr->val);
            map[ptr] = temp;
            ptr=ptr->next;
        }
        
        Node *dummy = new Node(0);
        dummy->next = map[head];
        ptr = head;
        
        while(ptr){
            map[ptr]->random = map[ptr->random];
            map[ptr]->next = map[ptr->next];
            ptr=ptr->next;
        }
        
        return dummy->next;
        
    }
};