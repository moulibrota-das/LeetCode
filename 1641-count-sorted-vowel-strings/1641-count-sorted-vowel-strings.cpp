class Solution {
public:
    int solve(int i, int n,vector<vector<int>>& dp){
        if(n == 0){
            return 1;
        }
        if(dp[n][i]!=-1) return dp[n][i];
        int count = 0;
        for(int j=i; j<5; j++){
            count = count + solve(j, n-1,dp); 
        }
        return dp[n][i] = count;
    }
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1,vector<int>(5,-1));
        return solve(0,n,dp);
    }
};