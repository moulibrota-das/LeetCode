class Solution {
public:
    int dir[5] = {0,1,0,-1,0};
    void dfs(int i, int j, int time, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int m = grid.size(), n = grid[0].size();        
        vis[i][j] = time;
        
        for(int d = 0; d<4; d++){
            int x = i + dir[d], y = j + dir[d + 1];
            if(min(x,y)>=0 && x<m && y<n && grid[x][y] == 1){
                if(vis[x][y] == -1 || vis[x][y] > (time + 1))
                    dfs(x,y,time+1,grid,vis);
            }
        }
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,-1));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    dfs(i,j,0,grid,vis);
                }
            }
        }
        
        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j] == -1 && grid[i][j] == 1) return -1;
                count = max(count, vis[i][j]);
            }
        }
        return count;
    }
};