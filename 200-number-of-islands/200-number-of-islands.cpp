class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis, int n, int m){
        vis[i][j] = 1;
        
        if(i+1 < n && grid[i+1][j] == '1' && !vis[i+1][j]){
            dfs(i+1,j,grid,vis,n,m);
        }
        if(i-1 >= 0 && grid[i-1][j] == '1' && !vis[i-1][j]){
            dfs(i-1,j,grid,vis,n,m);
        }
        if(j+1 < m && grid[i][j+1] == '1' && !vis[i][j+1]){
            dfs(i,j+1,grid,vis,n,m);
        }
        if(j-1 >= 0 && grid[i][j-1] == '1' && !vis[i][j-1]){
            dfs(i,j-1,grid,vis,n,m);
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(i,j,grid,vis,n,m);
                    count++;
                }
            }
        }
        return count;
    }
};