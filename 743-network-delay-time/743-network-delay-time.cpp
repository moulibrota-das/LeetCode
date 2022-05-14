class Solution {
public:
    void dfs(int i,vector<int> &sum, vector<vector<pair<int,int>>>& adj){
        
        for(auto it : adj[i]){
                    if(sum[i] + it.second < sum[it.first]){
                        sum[it.first] = min(sum[it.first] , sum[i] + it.second);
                        dfs(it.first,sum,adj);
                    }

        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> sum(n+1, INT_MAX);
        sum[k] = 0;
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int> vis(n+1,0);
        dfs(k,sum,adj);
        
        int ans = -1;
        for(int i = 1; i<=n; i++){
            ans = max(ans,sum[i]);
        }
        
        if(ans == INT_MAX) return -1;
        else return ans;

    }
};