class Solution {
public:
    int dir[5] = {0,1,0,-1,0};
    
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>& vis){
        int m = board.size(), n = board[0].size();
        vis[i][j] = 1;
        
        for(int d=0; d<4; d++){
            int x = i + dir[d], y = j + dir[d + 1];
            if(min(x,y) >= 0 && x<m && y<n && board[x][y] == 'O' && !vis[x][y])
                dfs(x,y,board,vis);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        for(int i=0; i<n; i++){
            if(board[0][i] == 'O' && !vis[0][i])
                dfs(0,i,board,vis);
            if(board[m-1][i] == 'O' && !vis[m-1][i])
                dfs(m-1,i,board,vis);
        }
        
        for(int i=0; i<m; i++){
            if(board[i][0] == 'O' && !vis[i][0])
                dfs(i,0,board,vis);
            if(board[i][n-1] == 'O' && !vis[i][n-1])
                dfs(i,n-1,board,vis);
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};