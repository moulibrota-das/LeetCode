class Solution {
public:
    int lcs(string X, string Y,int m,int n){
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(X[i-1]==Y[j-1]) dp[i][j]= 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[m][n];
    }
    int minDistance(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        return m+n-2*lcs(s1,s2,m,n) ;
    }
};