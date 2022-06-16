class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int size = 0, p=0 ,q=0;
        
        for(int i=0; i<n; i++){
            for(int g = 0, j = i; j<dp.size(); j++, g++){
                
                if(i == 0){
                    dp[g][j] = true;
                    if(i+1 > size){
                        size = i+1;
                        p = g;
                        q = j;
                    }
                } 
                else if(i == 1 && s[g] == s[j]){
                    dp[g][j] = true;
                    if(i+1 > size){
                        size = i+1;
                        p = g;
                        q = j;
                    }
                }
                else if(s[g] == s[j] && dp[g+1][j-1] == true){
                    dp[g][j] = true;
                    if(i+1 > size){
                        size = i+1;
                        p = g;
                        q = j;
                    }
                }
                else{
                    dp[g][j] = false;
                }
            }
        }
        string ans = "";
        for(int i = p; i<=q; i++){
            ans += s[i];
        }
        
        return ans;
    }
};