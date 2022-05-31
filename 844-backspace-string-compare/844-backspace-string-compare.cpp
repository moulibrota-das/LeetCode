class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size(), m = t.size();
        string s1 = "", s2 ="";
        int count = 0;
        for(int i=n-1; i>=0; i--){
            if(s[i] == '#'){
                count++;
            }
            else if(count != 0){
                count--;
            }
            else{
                s1 = s[i] + s1;
            }
        }
        count = 0;
        for(int i=m-1; i>=0; i--){
            if(t[i] == '#'){
                count++;
            }
            else if(count != 0){
                count--;
            }
            else{
                s2 = t[i] + s2;
            }
        }
        
        return s1 == s2;
    }
};