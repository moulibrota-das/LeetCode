class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), far = 0, curr = 0, count = 0;
        
        for(int i = 0; i<nums.size()-1; i++){
            far = max(far, nums[i] + i);
            if(i == curr){
                count++;
                curr = far;
            }
        }
        
        return count;
    }
};