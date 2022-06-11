class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = 0;
        
        for(int i=0; i<n; i++){
            total += nums[i];
        }
        
        int sum = 0, target = total - x;
        int ans = -1, start = 0, end = 0;
        
        if(target == 0) return n;
        else if(target < 0) return -1;
        
        while(end < n){
            sum += nums[end];
            if(sum == target){
                ans = max(ans,(end - start + 1));
            }
            else if(sum > target){
                while(sum > target){
                    sum -= nums[start];
                    start++;
                }
                if(sum == target)
                    ans = max(ans,(end - start + 1));    
            }
            
            end++;
        }   
        
        if(ans == -1) return ans;
        else return n - ans;
    }
};