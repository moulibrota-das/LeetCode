class Solution {
public:
    int dir[5] = {0, 1, 0, -1, 0};
    
    void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<int>>& heights, int height){    
        int n = heights[0].size(), m = heights.size();
        if(i<0 || i>=m || j<0 || j>=n || vis[i][j] || heights[i][j] < height)
            return;
        
        vis[i][j] = true;
        
        for(int d = 0; d<4; d++){
            int x = i + dir[d], y = j + dir[d + 1];
            dfs(x, y, vis, heights, heights[i][j]);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights[0].size(), m = heights.size();
        vector<vector<int>> ans;
        vector<vector<bool>> pacific(m, vector<bool>(n,0));
        vector<vector<bool>> atlantic(m, vector<bool>(n,0));
        
        for(int i=0; i<m; i++){
            dfs(i, 0, pacific, heights, INT_MIN);
            dfs(i, n-1, atlantic, heights, INT_MIN);
        }
        
        for(int i=0; i<n; i++){
            dfs(0, i, pacific, heights, INT_MIN);
            dfs(m-1, i, atlantic, heights, INT_MIN);
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        
        return ans;
    }
};