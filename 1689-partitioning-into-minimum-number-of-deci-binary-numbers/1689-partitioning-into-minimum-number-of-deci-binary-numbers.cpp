class Solution {
public:
    int minPartitions(string n) {
        int max_digit = 0;
        
        for(auto it:n){
            if(it-'0' == 9) return 9;
            max_digit = max(max_digit, it - '0');
        }
        return max_digit;
    }
};