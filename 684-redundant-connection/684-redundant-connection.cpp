class Solution {
public:
    
    int findParent(int node, vector<int>& parent){
        if(node == parent[node])
            return node;
        
        return parent[node] = findParent(parent[node], parent);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> rank(n+1,0), parent(n+1);
        
        for(int i = 1; i<=n; i++){
            parent[i] = i;
        }
        
        vector<int> ans(2);
        
        for(auto it : edges){
            int u = findParent(it[0], parent), v = findParent(it[1], parent);
            
            if(u == v){
                ans = it;
            }
            
            if(rank[u] < rank[v]){
                parent[v] = u;
            }
            else if(rank[v] < rank[u]){
                parent[u] = v;
            }
            else{
                parent[v] = u;
                rank[u]++;
            }
        }
        
        return ans;
    }
};