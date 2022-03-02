class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size()) return false;
        if(s.size() == 0) return true;
        
        int n = s.size();
        int p = 0;
        
        for(char it : t){
            if(p < n && s[p] == it){
                p++;
            }
        }
        
        if(p==n) return true;
        else return false;
    }
};