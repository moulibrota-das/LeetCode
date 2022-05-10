class Solution {
public:
        void solve(int i, int target, vector<int>& temp, vector<vector<int>> &ans,vector<int>& candidates){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target < 0) return;
            
        for(int j = i; j<candidates.size(); j++){
            if(j == i || candidates[j] != candidates[j-1]){ // checking no combi. start with same element;
                temp.push_back(candidates[j]);
                solve(j+1,target - candidates[j], temp, ans, candidates);
                temp.pop_back();
            }
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(0,target, temp, ans, candidates);
        return ans;
    }
};