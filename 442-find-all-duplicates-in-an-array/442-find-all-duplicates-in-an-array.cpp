class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            int node = abs(nums[i]);
            if(nums[node - 1] > 0){
                nums[node - 1] = nums[node - 1] * -1;
            }
            else{
                ans.push_back(node);
            }
        }
        
        return ans;
    }
};