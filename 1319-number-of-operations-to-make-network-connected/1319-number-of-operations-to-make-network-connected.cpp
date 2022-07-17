class Solution {
public:
    void dfs(int i, int p, vector<int>& vis, vector<vector<int>>& adj, int& count){
        vis[i] = 1;
        
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(it, i, vis, adj, count);
            }
            else if(it != p){
                count++;
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int s = connections.size();
        int extra = s - (n-1);
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        int comp = 0, count = 0;
        for(int i=0; i<n; i++){
           if(!vis[i]){
               dfs(i,-1,vis,adj,count);
               comp++;
           }
        }
        
        if(s >= (n - 1)) return comp - 1;
        else return -1;
    }
};