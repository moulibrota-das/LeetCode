class Solution {
public:
        int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m){
        vis[i][j] = 1;
        int l=0,r=0,u=0,d=0;
            
        if(i+1 < n && grid[i+1][j] == 1 && !vis[i+1][j]){
            d = dfs(i+1,j,grid,vis,n,m);
        }
        if(i-1 >= 0 && grid[i-1][j] == 1 && !vis[i-1][j]){
            u = dfs(i-1,j,grid,vis,n,m);
        }
        if(j+1 < m && grid[i][j+1] == 1 && !vis[i][j+1]){
            r = dfs(i,j+1,grid,vis,n,m);
        }
        if(j-1 >= 0 && grid[i][j-1] == 1 && !vis[i][j-1]){
            l = dfs(i,j-1,grid,vis,n,m);
        }
        
        return 1 + l + r + d + u;   
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    int curr = dfs(i,j,grid,vis,n,m);
                    ans = max(ans,curr);
                }
            }
        }
        return ans;
    }
};