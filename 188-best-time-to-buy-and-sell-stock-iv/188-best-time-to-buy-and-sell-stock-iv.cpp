class Solution {
public:
    int solve(int i, int k, int p, int n, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(i == n){
            return 0;
        }
        if(k == 0) return 0;
        
        if(dp[i][p][k] != -1) return dp[i][p][k];
        
        int hold = INT_MIN, sell = INT_MIN, buy = INT_MIN;
        
        if(p == 0){
            buy = max(-prices[i] + solve(i+1, k, 1, n, prices, dp), solve(i+1, k, p, n, prices, dp));
        }
        else{
            sell = max(prices[i] + solve(i+1, k-1, 0, n, prices, dp), solve(i+1,k,p,n,prices,dp));
        }
        
        return dp[i][p][k] = max(buy, sell);
    }
    
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(0,k,0,prices.size(), prices, dp);
    }
};