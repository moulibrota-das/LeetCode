class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // we can find the median by only sort the median element in the n/2 position
        nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
        
        long long avg = nums[nums.size()/2];
        long long ans = 0;
        
        for(auto it:nums){
            ans += abs(avg - it);
        }
        return ans;
    }
};