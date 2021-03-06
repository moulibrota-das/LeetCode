class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set;
        for(auto it:wordList) set.insert(it);
        
        if(set.count(endWord) == 0) return 0;
        
        int depth = 1;
        
        queue<string> q;
        q.push(beginWord);
        
        while(!q.empty()){
            int n = q.size();
            depth++;
            
            while(n--){
                string cur = q.front();
                q.pop();                
                
                for(int i=0; i<cur.size(); i++){
                    string temp = cur;
                    
                    for(char ch = 'a'; ch <= 'z'; ch++){
                        temp[i] = ch;
                        
                        if(temp == endWord) return depth;
                        
                        if(temp != cur && set.count(temp) > 0){
                            q.push(temp);
                            set.erase(temp);
                        }
                    }
                }
            }
            
            
        }
            return 0;
    }
};