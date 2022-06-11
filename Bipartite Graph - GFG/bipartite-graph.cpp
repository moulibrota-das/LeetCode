// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
bool dfs(int src, int col,vector<int>adj[], int color[]){
       color[src]=col;
       for(auto it: adj[src]){
           if(!color[it] && !dfs(it,3-col,adj,color))
               return false;
           if(color[it] && color[it]!=3-col)
               return false;
       }
       return true;
}
bool isBipartite(int V, vector<int>adj[]){
    int color[V];
    for(int i=0;i<V;i++)
        color[i]=0;
    for(int i=0;i<V;i++)
        if(!color[i] && !dfs(i,1,adj,color))
            return false;
    return true;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends