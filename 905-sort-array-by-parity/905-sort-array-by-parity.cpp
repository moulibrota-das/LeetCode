class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int l=0,r=0;
        while(r < n){
            if(nums[r] % 2 == 0){
                swap(nums[l],nums[r]);
                l++;
                r++;
            }
            else{
                r++;
            }
        }
        return nums;
    }
};