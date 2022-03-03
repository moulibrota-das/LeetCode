// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i, int j, string temp, vector<string>& ans, vector<vector<int>> &m, int n, int di[], int dj[]){
        if(i == n-1 && j==n-1){
            ans.push_back(temp);
            return;
        }
        
        string dir = "DLRU";
        
        for(int index=0; index<4; index++){
            int nexti = i + di[index];
            int nextj = j + dj[index];
            
            if(nexti >= 0 && nextj>=0 && nexti<n && nextj < n &&  m[nexti][nextj] == 1){
                m[i][j] = 0;
                solve(nexti, nextj, temp+dir[index],ans,m,n,di,dj);
                m[i][j] = 1;
            }
        }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        if(m[n-1][n-1] == 0 || m[0][0] == 0) return {"-1"};
        
        vector<string> ans;
        int di[] = {1,0,0,-1};
        int dj[] = {0,-1,1,0};
        solve(0,0,"",ans,m,n,di,dj);
        
        if(ans.size() == 0) return {"-1"};
        else return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends