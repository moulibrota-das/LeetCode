class Solution {
public:
    void solve(int i,string res, string digits, vector<string> &phoneChar, vector<string> &ans, int n){
        if(i == n){
            ans.push_back(res);
            return;
        }
        
        for(int j = 0; j<phoneChar[digits[i] - '0'].size(); j++){
            solve(i+1,res + phoneChar[digits[i] - '0'][j], digits, phoneChar, ans, n);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        vector<string>phoneChar = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        if(digits.size() == 0)
            return ans;
            
        solve(0,"",digits,phoneChar, ans, digits.size());
        return ans;
    }
};