class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0, r= nums.size()-1;
        int ansL = -1, ansR = -1;
        
        while(l <= r){
            int mid = (l+r)/2;
            
            if(nums[mid] == target){
                ansL = mid;
                 r = mid-1;
            }
            else if(nums[mid] >= target){
                r = mid-1;
            }
            else{
                l = mid + 1;
            }
        }
        
        l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = (l+r)/2;
            
            if(nums[mid] == target){
                ansR = mid;
                l = mid+1;
            }
            else if(nums[mid] <= target){
                l = mid+1;
            }
            else{
                r = mid - 1;
            }
        }
        
        return {ansL, ansR};
    }
};