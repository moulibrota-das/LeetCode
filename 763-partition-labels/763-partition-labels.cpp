class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        map<char,int> map;
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            map[s[i]] = i;
        }
        
        int end = map[s[0]];
        int count = 0;
        
        for(int i=0; i<n; i++){
            end = max(end, map[s[i]]);
            count++;
            
            if(i == end){
                ans.push_back(count);
                end = 0;
                count = 0;
            } 
        }
        
        return ans;
    }
};