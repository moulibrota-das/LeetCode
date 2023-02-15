//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<vector<int>> adj(N);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        queue<pair<int,int>> q;
        vector<int> dis(N, INT_MAX);
        
        dis[src] = 0;
        q.push({src, 0});
        
        while(!q.empty()){
            int u = q.front().first;
            int v = q.front().second;
            q.pop();
            
            for(auto it:adj[u]){
                if(dis[it] > v+1){
                    dis[it] = v+1;
                    q.push({it, v+1});
                }
            }
        }
        
        for(int i=0; i<N; i++){
            if(dis[i] == INT_MAX){
                dis[i] = -1;
            }
        }
        
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends