class Solution {
public:
    int solve(int i, int target, vector<int>& coins, vector<vector<int>>& dp){
        if(target == 0) return 0;
        if(i == 0){
            if(target%coins[i] == 0){
                return target/coins[i];
            }
            else return 1e9;
        }
        
        if(dp[i][target] != -1) return dp[i][target];
        
        int take = INT_MAX;
        if(target >= coins[i]){
            take = 1 + solve(i,target - coins[i], coins,dp);
        }
        int notTake = solve(i-1,target, coins,dp);
        
        return dp[i][target] = min(take,notTake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans = solve(coins.size() - 1,amount,coins,dp);
        if(ans >= 1e9) return -1;
        else return ans;
    }
};