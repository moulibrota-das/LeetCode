class Solution {
public:
    int solve(int i, int j,vector<vector<int>>& obstacleGrid,int n, int m, vector<vector<int>>& dp){
        if(i == n-1 && j == m-1){
            return 1;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int down = 0, right = 0;
        
        if(i+1 < n && obstacleGrid[i+1][j] == 0){
            down = solve(i+1,j,obstacleGrid,n,m,dp);
        }
        if(j+1 < m && obstacleGrid[i][j+1] == 0){
            right = solve(i,j+1,obstacleGrid,n,m,dp);
        }
        
        return dp[i][j] = down + right;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;
        
        return solve(0,0,obstacleGrid,n,m,dp);
    }
};