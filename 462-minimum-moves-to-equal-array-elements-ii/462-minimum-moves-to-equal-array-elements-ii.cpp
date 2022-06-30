class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        long long avg = nums[nums.size()/2];
        long long ans = 0;
        
        for(auto it:nums){
            ans += abs(avg - it);
        }
        return ans;
    }
};