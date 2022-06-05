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
    int solve(int i, int n, vector<string>& board){
        if(i == n){
            return 1;
        }
        int sum = 0;
        
        for(int j=0; j<n; j++){
            if(check(i,j,n,board)){
                board[i][j] = 'Q';
                sum += solve(i+1,n,board);
                board[i][j] = '.';
            }
        }
        return sum;
    }
    int totalNQueens(int n) {
        string s(n,'.');
        vector<string> board(n,s);
        return solve(0,n,board);
    }
};