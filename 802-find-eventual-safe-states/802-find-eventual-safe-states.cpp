class Solution {
public:
    
    /*  checks if the node is safe or not
        
        the nodes whoose outgoing edges does not lead to a terminal node will be
        cyclic.
    */
    bool dfs(int i, vector<int>& vis, vector<int>& res, vector<vector<int>>& graph){
        vis[i] = 1;
        res[i] = 1;
        
        for(auto it:graph[i]){
            if(vis[it] == 0 && dfs(it, vis, res, graph)){
                continue;
            }
            else if(res[it] == 1 || vis[it] == 1){
                return false;
            }
        }
        res[i] = 0;
        vis[i] = 2;
        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> res(n, 0);
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            if(vis[i] == 0 && dfs(i,vis, res, graph)){
                ans.push_back(i);
            }
            else if(vis[i] == 2){
                ans.push_back(i);
            }
        }
        
        
        return ans;
    }
};