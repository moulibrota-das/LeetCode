class Solution {
public:
    int solve(int i, vector<int> &vis, int n, int& c){
        if(i==n+1){
            return 1;
        }
        
        int count = 0;
        for(int j=1; j<=n; j++){
            if(vis[j] == 0 && (j%i == 0 || i%j == 0)){
                vis[j] = 1;
                count = count + solve(i+1,vis,n,count);
                vis[j] = 0;
            }
        }
        return count;
    }
    int countArrangement(int n) {
        int count = 0;
        vector<int> vis(n+1,0);
        
        return solve(1,vis,n,count);
    }
};