class Solution {
public:
    bool dfs(int i, vector<int>& vis, vector<int>& cur_vis, vector<vector<int>>& adj){
        vis[i] = 1;
        cur_vis[i] = 1;
        
        for(auto it:adj[i]){
            if(!vis[it] && dfs(it, vis, cur_vis, adj)){
                return true;
            }
            else if(cur_vis[it]) return true;
        }
        cur_vis[i] = 0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> cur_vis(numCourses, 0);
        vector<int> vis(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        
        for(auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        
        for(int i=0; i<numCourses; i++){
            if(!vis[i] && dfs(i, vis, cur_vis, adj)){
                return false;
            }
        }
        return true;
    }
};