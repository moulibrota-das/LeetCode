class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> map;
        int start = 0, end = 0, ans = 0;
        
        while(end < s.size()){
            if(map.find(s[end]) == map.end() || map[s[end]] < start){
                map[s[end]] = end;
            }
            else{
                int curSize = end - start;
                ans = max(curSize, ans);
                start = map[s[end]] + 1;
                map[s[end]] = end;
            }
            end++;
        }
        ans = max(ans,(end - start));
        
        return ans;
    }
};