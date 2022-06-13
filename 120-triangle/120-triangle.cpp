class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle){
        if(i == 0){
            return triangle[0][0];
        }
        
        int lp = 1e9, rp = 1e9;
        if(j-1 >= 0){
            lp = triangle[i][j] + solve(i-1,j-1,triangle);
        }
        if(j < triangle[i-1].size()){
            rp = triangle[i][j] + solve(i-1,j,triangle);
        }
        
        return  min(lp,rp);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp (n,-1);
        dp = triangle[n-1];        
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<triangle[i].size(); j++){
                int temp = triangle[i][j] + min(dp[j+1], dp[j]);
                dp[j] = temp;
            }
        }
        return dp[0];
    }
};