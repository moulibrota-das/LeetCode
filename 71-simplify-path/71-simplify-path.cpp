class Solution {
public:
    string simplifyPath(string path) {
        deque<string> q;
        
        for(int i=0; i<path.size(); i++){
            if(path[i] == '/') continue;
            
            string temp = "";
            while(i < path.size() && path[i] != '/'){
                temp += path[i];
                i++;
            }
            
            if(temp == ".." && !q.empty()) q.pop_back();
            else if(temp != "." && temp != "" && temp != "..")
                q.push_back(temp);
            
        }
        
        string ans = "";
        while(!q.empty()){
            ans = ans + "/" + q.front() ;
            q.pop_front();
        }
        
        return ans=="" ? "/" : ans;
    }
};