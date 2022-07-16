class Solution {
public:
       
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        vector<int> ans;
        queue<int> q;
        
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int cur = q.front();
            ans.push_back(cur);
            q.pop();
            
            for(auto it:adj[cur]){
                if(--indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        if(ans.size() == numCourses) return ans;
        else return {};
    }
};