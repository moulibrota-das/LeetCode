class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        if(n == 0) return ans;
        
        int start = nums[0];
        for(int i=0; i<n; i++){
            if(i == n-1 || nums[i] + 1 != nums[i+1]){
                
                if(nums[i] == start) 
                    ans.push_back(to_string(start));
                else
                    ans.push_back(to_string(start) + "->" + to_string(nums[i]));
                
                if(i != n-1)
                    start = nums[i+1];
            }
        }
        
        return ans;
    }
};