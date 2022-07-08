class Solution {
public:
    int dir[5] = {0,1,0,-1,0};
    void paint(int i, int j, vector<pair<int,int>>& q, vector<vector<int>>& grid){
        if(min(i,j) >= 0 && max(i,j) < grid.size() && grid[i][j] == 1){
            grid[i][j] = 2;
            q.push_back({i,j});
            for(int d=0; d<4; d++)
                paint(i + dir[d], j + dir[d + 1], q, grid);
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int,int>> q;
        
        for(int i=0; q.size() == 0 && i<n; i++)
            for(int j=0; q.size() == 0 && j<n; j++)
                paint(i,j,q,grid);
        // paint one of my island as 2
        
        while(q.size()){ //bfs expansion from our first island
            vector<pair<int,int>> temp;
            
            for(auto [i,j] : q){
                for(int d=0; d<4; d++){
                    int x = i + dir[d], y = j + dir[d + 1];
                    if(min(x,y) >= 0 && max(x,y) < n){
                        if(grid[x][y] == 1){ // if on expansion we reach island 2
                            return grid[i][j] - 2;
                        }
                        else if(grid[x][y] == 0){ // if expansion lead to water we incerase the length
                            grid[x][y] = grid[i][j] + 1;
                            temp.push_back({x,y});
                        }
                    }
                }
            }
            q = temp;
        }
        return 0;
    }
};