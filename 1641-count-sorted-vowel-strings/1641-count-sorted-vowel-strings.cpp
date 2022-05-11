class Solution {
public:
    void solve(int i, int& count, int n){
        if(n == 0){
            count++;
            return;
        }
        
        for(int j=i; j<5; j++){
            solve(j, count, n-1); 
        }
    }
    int countVowelStrings(int n) {
        vector<vector<int>> dp();
        int count = 0;
        solve(0,count,n);
        return count;
    }
};