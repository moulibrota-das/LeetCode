//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> indegree(N);
	    vector<int> topo;
	    vector<vector<int>> adj(N);
	    for(auto item: prerequisites){
	        adj[item.first].push_back(item.second);
	        indegree[item.second]++;
	    }
	    
	    queue<int> q;
	    
	    for(int i=0; i<N; i++){
	        if(indegree[i] == 0) q.push(i);
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        topo.push_back(node);
	        q.pop();
	        
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
	    
	    if(topo.size() == N) return true;
	    else return false;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends