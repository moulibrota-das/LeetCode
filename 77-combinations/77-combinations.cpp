class Solution {
public:
        void solve(int i, vector<int>& temp, vector<vector<int>> &ans, int k, int n){
        if(k == 0){
            ans.push_back(temp);
            return;
        }
        if(i > n) return;
        
        for(int j = i; j<=n; j++){
            temp.push_back(j);
            solve(j+1, temp, ans, k-1, n);
            temp.pop_back();
        }        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(1,temp,ans,k,n);
        return ans;
    }
};