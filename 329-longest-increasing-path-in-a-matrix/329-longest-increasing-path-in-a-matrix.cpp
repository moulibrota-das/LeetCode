class Solution {
public:
    int solve(int i,int j, vector<vector<int>> &dir,vector<vector<int>> &dp, vector<vector<int>>& matrix, int n, int m){
        int s = 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        for(int z=0; z<4; z++){
            int row = i + dir[z][0];
            int col = j + dir[z][1];
            
            if(row>= 0 && row < n && col>=0 && col<m && matrix[i][j] < matrix[row][col]){
                s = max(s,solve(row,col,dir,dp,matrix,n,m));
            }
        }
        
        return dp[i][j] = 1 + s;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(dp[i][j] == -1)
                    ans = max(ans, solve(i,j,dir,dp,matrix,n,m));
                else
                    ans = max(ans,dp[i][j]);
            }
        }
        
        return ans;
    }
};