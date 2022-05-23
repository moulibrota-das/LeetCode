class Solution {
public:
    int solve(int i, int o, int z, vector<string>& strs, int m, int n,vector<vector<vector<int>>>& dp){
        int count0 = 0;
        for(auto it:strs[i]){
            if(it == '0') count0++;
        }
        
        if(i == 0){
            if(o + strs[i].size() - count0 <= n && z + count0 <= m)
                return 1;
            else 
                return 0;
        }
        
        if(dp[o][z][i] != -1) return dp[o][z][i];
        
        int take = INT_MIN;
        if(o + strs[i].size() - count0 <= n && z + count0 <= m){
            take = 1 + solve(i-1, o + strs[i].size() - count0, z + count0, strs, m, n, dp);
        }
        
        int notTake = solve(i-1, o, z, strs, m, n, dp);
        
        return dp[o][z][i] = max(take, notTake);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        vector<pair<int,int>> freq(s,{0,0});
        
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1, vector<int>(s,-1)));
        
        return solve(s-1, 0, 0, strs, m, n, dp);
    }
};