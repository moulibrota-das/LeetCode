class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), goal = n-1;
        bool ans = false;

        for(int i = n-1; i>=0; i--){
            if(i+nums[i] >= goal){
                ans = true;
                goal = i;
            }
            else ans = false;
        }
        
        return ans;
    }
};