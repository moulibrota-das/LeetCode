class Solution {
public:
    int countOrders(int n) {
        long long ans = 1;
        long long m = 1e9 + 7;
        for(long long i=1; i<= n; i++){
            ans = (ans * i)%m; //pickup can be arranged in n! ways
            
            ans = (ans * (2 * i - 1))%m; //delivery can be arranged in 1*3*5*.....(2n - 1) ways
            
        }
        
        return ans;
    }
};