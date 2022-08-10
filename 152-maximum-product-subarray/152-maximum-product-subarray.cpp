class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr = nums[0], imax = curr, imin = curr;
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i] < 0)
                swap(imax,imin);
            
            imax = max(nums[i], imax*nums[i]);
            imin = min(nums[i], imin*nums[i]);
            
            curr = max(curr, imax);
        }
        
        return curr;
    }
};