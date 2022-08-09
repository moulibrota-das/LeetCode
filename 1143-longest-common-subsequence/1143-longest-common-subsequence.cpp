class Solution {
public:
    int solve(int i, int j, string& nums1, string& nums2, vector<vector<int>>& dp){
        if(i == nums1.size() || j == nums2.size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];

        int take1 = solve(i, j+1, nums1, nums2, dp);
        int take2 = solve(i+1, j, nums1, nums2, dp);
        int sp = 0;
        if(nums1[i] == nums2[j]){
            sp = 1 + solve(i+1, j+1, nums1, nums2, dp);
        }
        
        return dp[i][j] = max(take1, max(take2, sp));
    }
    
    int longestCommonSubsequence(string nums1, string nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int ans = 0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans,dp[i][j]);
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};