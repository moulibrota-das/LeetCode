class Solution {
public:
    int dfs(int i, vector<int>& informTime, vector<vector<int>>& adj){
        int mx = 0;
        for(auto it:adj[i]){
            mx = max(mx, dfs(it, informTime, adj));
        }
        
        return informTime[i] + mx;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        
        for(int i=0; i<n; i++){
            if(manager[i] != -1)
                adj[manager[i]].push_back(i);
        }
    
        return dfs(headID, informTime, adj);
    }
};