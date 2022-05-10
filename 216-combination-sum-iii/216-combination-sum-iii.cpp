class Solution {
public:
    void solve(int i, vector<int>& temp, vector<vector<int>> &ans, int k, int n){
        if(k == 0){
            if(n == 0)
                ans.push_back(temp);
            return;
        }
        if(i > 9) return;
        
        if(i <= n && k > 0){
            temp.push_back(i);
            solve(i+1, temp, ans, k-1, n-i);
            temp.pop_back();
        }

        solve(i+1, temp, ans, k, n);
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1,temp,ans,k,n);
        return ans;
    }
};