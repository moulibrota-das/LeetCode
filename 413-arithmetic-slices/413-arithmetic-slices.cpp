class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        
        vector<int> arr(n,0);
        
        for(int i=2; i<n; i++){
            if((nums[i] - nums[i-1]) == (nums[i-1] - nums[i-2])){
                arr[i] = arr[i-1] + 1;
            }
        }
        
        int sum = 0;
        for(auto it : arr){
            sum += it;
        }
        
        return sum;
    
    }
};