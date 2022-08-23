class Solution {
public:
    vector<int> dir = {0,1,0,-1,0};
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis){
        if(min(i,j) < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || vis[i][j])
            return;
        
        vis[i][j] = 1;
        
        for(int d = 0; d<4; d++){
            int x = i + dir[d], y = j + dir[d + 1];
            dfs(x,y,grid, vis);
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        
        for(int i=0; i<m; i++){
            if(grid[i][0] == 1 && !vis[i][0])
                dfs(i,0,grid,vis);
            if(grid[i][n-1] == 1 && !vis[i][n-1])
                dfs(i,n-1,grid,vis);
        }
        
        for(int i=0; i<n; i++){
            if(grid[0][i] == 1 && !vis[0][i])
                dfs(0,i,grid,vis);
            if(grid[m-1][i] == 1 && !vis[m-1][i])
                dfs(m-1,i,grid,vis);
        }
        
        int count = 0;
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == 1 && !vis[i][j])
                    count++;
        
        return count;
    }
};