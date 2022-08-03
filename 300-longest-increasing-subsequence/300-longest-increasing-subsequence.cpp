class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        dp[0] = 1;
        int ans = dp[0];
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                int take = 0;
                
                if(nums[j] < nums[i]){
                    take = 1 + dp[j];
                }
                dp[i] = max(take, dp[i]);
                ans = max(ans,dp[i]);
            }
        }
        return ans;
    }
};