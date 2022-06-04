class Solution {
public:
    bool check(int i, int j, int n, vector<string>& board){
        for(int z=i-1; z>=0; z--){
            if(board[z][j] == 'Q') return false;
            else if(j-(i-z) >=0 && board[z][j-(i-z)] == 'Q') return false;
            else if(j+(i-z) < n && board[z][j+(i-z)] == 'Q') return false;
        }
        return true;
    }
    void solve(int i, int n, vector<vector<string>>& ans, vector<string>& board){
        if(i == n){
            ans.push_back(board);
            return;
        }
        
        for(int j=0; j<n; j++){
            if(check(i,j,n,board)){
                board[i][j] = 'Q';
                solve(i+1,n,ans,board);
                board[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> board(n,s);
        solve(0,n,ans,board);
        return ans;
    }
};