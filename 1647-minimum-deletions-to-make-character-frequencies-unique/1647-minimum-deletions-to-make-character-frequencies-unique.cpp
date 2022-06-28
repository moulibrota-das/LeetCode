class Solution {
public:
    int minDeletions(string s) {
        vector<char> fr(s.size() + 1,'#');
        map<char,int> map;
        
        for(auto it:s)
            map[it]++;
        
        int ans = 0;
        for(auto it:map){
            int index = it.second;
            while(fr[index] != '#'){
                index--;
                ans++;
            }
            
            if(index > 0){
                fr[index] = it.first;
            }
        }
        
        return ans;
    }
};