class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        
        vector<pair<int,int>> move{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        queue<vector<int>> q;
        q.push({0,0,1});
        
        while(!q.empty()){
            int m = q.size();
            while(m--){
                vector<int> temp = q.front();
                q.pop();
                if(temp[0] == n-1 && temp[1] == n-1) return temp[2];
                
                for(auto it : move){
                    int r = temp[0] + it.first;
                    int c = temp[1] + it.second;
                    
                    if(r>=0 && r<n && c>=0 && c < n && grid[r][c] == 0){
                        q.push({r,c,temp[2] + 1});
                        grid[r][c] = 1;
                    }
                }
            }
        }
        return -1;
        
    }
};