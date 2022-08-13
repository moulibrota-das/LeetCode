class Solution {
public:
    int solve(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){
        if(i == word1.size()) return word2.size() - j;
        if(j == word2.size()) return word1.size() - i;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1e9;
        
        if(word1[i] == word2[j]){
            ans = solve(i+1, j+1, word1, word2, dp);
        }
        else{
            int rep = solve(i+1,j+1,word1, word2, dp);
            int ins = solve(i,j+1, word1, word2, dp);
            int del = solve(i+1,j,word1, word2, dp);
            
            ans = 1 + min(rep, min(ins,del));
        }        
        
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return solve(0,0,word1,word2,dp);
    }
};