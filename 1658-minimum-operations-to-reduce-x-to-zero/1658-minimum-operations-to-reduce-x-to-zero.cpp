class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        map<int,int> map;
        int total = 0;
        
        for(int i=0; i<n; i++){
            total += nums[i];
        }
        
        int sum = 0;
        int ans = INT_MAX;
        
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(sum == x){
                ans = min(ans,i+1);
            }
            if(total - sum == x){
                ans = min(ans,n-i-1);
            }
            if(map.find(x - (total - sum)) != map.end()){
                ans = min(ans, n-i + map[x - (total - sum)]);
            }
            map[sum] = i;
        }
        
        if(ans == INT_MAX) return -1;
        else return ans;
    }
};