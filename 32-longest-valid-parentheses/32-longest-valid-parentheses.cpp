class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stack;
        stack.push(-1);
        int n=s.length(), count = 0, ans = 0;
        for(int i=0;i<n;i++){
            
            if(s[i]=='('){
                stack.push(i);
            }
            else{
                stack.pop();
                if(stack.empty()){
                    stack.push(i);
                }
                count = i - stack.top();
                ans = max(ans,count);
            }
        }
        return ans;
    }
};