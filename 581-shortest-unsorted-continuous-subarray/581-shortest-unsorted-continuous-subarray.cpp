class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = 0, end = 0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                start = i;
                break;
            }
        }
        for(int i = nums.size()-2; i>=0; i--){
            if(nums[i] > nums[i+1]){
                end = i+1;
                break;
            }
        }
        
        int mi=INT_MAX, ma = INT_MIN;
        for(int i=start; i<=end; i++){
            mi = min(mi,nums[i]);
            ma = max(ma, nums[i]);
        }
        
        for(int i=start; i>=0; i--){
            if(mi < nums[i]){
                start = i;
            }
        }
        for(int i=end; i<nums.size(); i++){
            if(ma > nums[i]){
                end = i;
            }
        }
        return (end ==0 && start==0) ? 0 : end-start+1;
    }
};