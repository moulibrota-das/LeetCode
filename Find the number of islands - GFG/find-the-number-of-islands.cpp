//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}};
    void dfs(int i, int j, vector<vector<char>>& grid){
        if(grid[i][j] == '0') return;
        
        grid[i][j] = '0';
        
        for(auto item:dir){
            if(i + item[0] < 0 || i+item[0] >= grid.size() || j + item[1] < 0 || j+item[1] >= grid[0].size()){
                continue;
            }
            else{
                dfs(i+item[0], j+item[1], grid);
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int ans=0;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends