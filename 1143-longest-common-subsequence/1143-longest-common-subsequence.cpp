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
    
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return solve(0,0,text1,text2, dp);
    }
};