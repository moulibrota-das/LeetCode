class Solution {
public:
    void solve(int i, vector<int>& temp, vector<vector<int>> &ans,vector<int>& nums, int n){
        ans.push_back(temp);
        if(i >= n){
            return;
        }
        
        for(int j = i; j<n; j++){
            if(j == i || nums[j] != nums[j-1]){
                temp.push_back(nums[j]);
                solve(j+1, temp, ans, nums, n);
                temp.pop_back();
            }
        }        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        solve(0,temp,ans,nums,nums.size());
        return ans;
    }
};