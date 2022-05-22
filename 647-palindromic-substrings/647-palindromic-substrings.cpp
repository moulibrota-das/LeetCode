class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        
        int count = 0;
        
        for(int i=0; i<n; i++){
            
            for(int g = 0, j = i; j<dp.size(); j++, g++){
                
                if(i == 0){
                    dp[g][j] = true;
                    count++;
                } 
                else if(i == 1 && s[g] == s[j]){
                    dp[g][j] = true;
                    count++;
                }
                else if(s[g] == s[j] && dp[g+1][j-1] == true){
                    dp[g][j] = true;
                    count++;
                }
                else{
                    dp[g][j] = false;
                }
            }
        }
        return count;
    }
};