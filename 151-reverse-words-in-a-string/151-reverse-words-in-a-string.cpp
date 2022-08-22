class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;
        string temp = "";
        
        for(auto it:s){
            
            if(it != ' '){
                temp += it;
            }
            else if(it == ' ' && temp!= ""){
                arr.push_back(temp);
                temp = "";
            }
        }
        if(temp != "") arr.push_back(temp);
        
        temp = arr[arr.size() - 1];
        
        for(int i=arr.size() - 2; i>=0; i--){
            temp = temp + " " + arr[i];
        }
        
        return temp;
    }
};