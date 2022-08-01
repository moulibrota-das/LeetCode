class Solution {
public:
    int solve(int i, int n, string& s, vector<int>& dp){
        if(i == n){
            return 1;
        }
        
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        
        int take = 0, dTake = 0;
        string temp="";
        
        take = solve(i+1,n,s,dp);
        
        if(i < n-1){
            temp += s[i];
            temp += s[i+1];
            if(stoi(temp) <= 26){
                dTake = solve(i+2, n, s, dp);
            }
        }
        
        return dp[i] = take + dTake;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return solve(0,s.size(),s,dp);
    }
};