class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() == 1 || nums.size() == 2) return true;
        
        int n = nums.size()-1;
        int count = 0;
        bool ans1 = true, ans2 = true;
        
        while(n > 0){
            if(nums[n-1] > nums[n]){
                if(n > 1 && nums[n] < nums[n-2])
                    ans1 = false;
                
                count++;
                if(count > 1) ans1 = false;
            }
            n--;
        }
        count = 0, n=0;
        
        while(n < nums.size() - 1){
            if(nums[n] > nums[n+1]){
                if(n < nums.size() - 2 && nums[n] > nums[n+2])
                    ans2 = false;
                
                count++;
                if(count > 1) ans2 = false;
            }
            n++;
        }
        
        return ans1 | ans2;
        
    }
};