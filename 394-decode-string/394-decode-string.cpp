class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<char> stack;
        string ans = "";
        
        for(int i=0; i<n; i++){
            string temp = "";
            if(s[i] == ']'){
                while(stack.top() != '['){
                    temp = stack.top() + temp;
                    stack.pop();
                }
                stack.pop();
                
                string num = "";
                while(!stack.empty() && isdigit(stack.top())){
                    num = stack.top() + num;
                    stack.pop();
                }
                
                int m = stoi(num);
                
                while(m--){
                    for(int j=0; j<temp.size(); j++)
                        stack.push(temp[j]);
                }
                
                
            }
            else{
                stack.push(s[i]);
            }
        }
        
        while(!stack.empty()){
            ans = stack.top() + ans;
            stack.pop();
        }
        return ans;
    }
};