class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        dp[0] = 1;
        int ans = dp[0];
        
        for(int i=1; i<n; i++){
            int take = 0;
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    take = max(take, dp[j]);
                }
            }

            dp[i] = 1 + take;
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};