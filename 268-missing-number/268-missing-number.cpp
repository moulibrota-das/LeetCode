class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for(int it : nums){
            sum += it;
        }
        
        n = n*(n+1)/2;
        return n - sum;
    }
};