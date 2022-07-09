/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, map<Node*, Node*>& map){
        if(node == NULL) return NULL;
        
        Node* temp = new Node(node->val, {});
        map[node] = temp;
        
        for(auto it:node->neighbors){
            if(map.find(it) != map.end()){
                temp->neighbors.push_back(map[it]);
            }
            else{
                temp->neighbors.push_back(dfs(it,map));
            }
        }
        
        return temp;
    }
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> map;        
        return dfs(node,map);
    }
};