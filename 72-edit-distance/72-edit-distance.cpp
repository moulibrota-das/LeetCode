class Solution {
public:
    int solve(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1e9;
        
        if(word1[i] == word2[j]){
            ans = solve(i-1, j-1, word1, word2, dp);
        }
        else{
            int rep = solve(i-1,j-1,word1, word2, dp);
            int ins = solve(i,j-1, word1, word2, dp);
            int del = solve(i-1,j,word1, word2, dp);
            
            ans = 1 + min(rep, min(ins,del));
        }        
        
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, -1));
        return solve(word1.size()-1, word2.size()-1, word1, word2, dp);
        
//         for(int i=0; i<=word1.size(), i++)
//             dp[i][0] = i;
        
//         for(int i=0; i<=word2.size(), i++)
//             dp[0][i] = i;
        
//         for(int i=0; i<word1.size(); i++){
//             for(int j=0; j<word2.size(); j++){
//                 if(word1[i] == word2[j]){
//                    dp[i+1][j+1] = dp[i][j];
//                 }
//                 else{
//                     int rep = dp[i][j],word1, word2, dp);
//                     int ins = solve(i,j+1, word1, word2, dp);
//                     int del = solve(i+1,j,word1, word2, dp);

//                     ans = 1 + min(rep, min(ins,del));
//                 }
//             }
//         }
        
    }
};