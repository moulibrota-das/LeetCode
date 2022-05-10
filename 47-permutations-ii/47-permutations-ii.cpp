class Solution {
public:
    void solve(int i,vector<int>& temp,vector<int>& vis,vector<vector<int>>& ans,vector<int>& nums,int n){
        if(i == n){
            ans.push_back(temp);
            return;
        }
        
        for(int j = 0; j<n; j++){
            if(vis[j] || (j>0 && nums[j] == nums[j-1] && !vis[j-1]))
                continue;
            vis[j] = 1;
            temp.push_back(nums[j]);
            solve(i+1,temp,vis,ans,nums,n);
            vis[j] = 0;
            temp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n,0);
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        solve(0,temp,vis,ans,nums,n);
        return ans;
    }
};