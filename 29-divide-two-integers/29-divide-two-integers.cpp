class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long long ans = 0;
        int neg = dividend < 0 ^ divisor < 0 ? -1:1;
        
        long long dd = abs(dividend);
        long long dv = abs(divisor);
        
        for(int i=31; i>=0; i--){
            if((dv<<i) <= dd){
                dd -= dv<<i;
                ans += 1<<i;
            }
        }
        
        return neg*ans;
    }
};