class Solution {
public:
    int solve(int i, int target, vector<int>& coins, vector<vector<int>>& dp){
        if(target == 0){
            return 1;
        }
        if(i == 0){
            if(target % coins[i] == 0){
                return 1;
            }
            else return 0;
        }
        if(dp[i][target] != -1) return dp[i][target];
        
        int take = 0, notTake = 0;
        if(target - coins[i] >= 0){
            take = solve(i,target - coins[i], coins, dp);
        }
        notTake = solve(i-1, target, coins, dp);
        
        return dp[i][target] = take + notTake;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        
        return solve(n-1, amount, coins, dp);
    }
};