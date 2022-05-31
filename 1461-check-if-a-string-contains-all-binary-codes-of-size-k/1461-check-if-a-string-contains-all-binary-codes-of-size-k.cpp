class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = pow(2,k);
        if(n > s.size()) return false;
        set<string> set;
        
        string st="";
        for(int i=0; i<k; i++){
            st += s[i];
        }
        set.insert(st);
        for(int i=k; i<s.size(); i++){
            st = st.substr(1,k-1) + s[i];
            set.insert(st);
        }
        
        if(set.size() == n) return true;
        else return false;
    }
};