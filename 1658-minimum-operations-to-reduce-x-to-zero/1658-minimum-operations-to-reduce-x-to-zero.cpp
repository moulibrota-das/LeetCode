class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        map<int,int> map;
        int sum = 0;
        
        for(int i=0; i<n; i++){
            sum += nums[i];
            map[sum] = i;
        }
        
        sum = 0;
        int ans = INT_MAX;
        if(map.find(x) != map.end()){
            ans = map[x] + 1;
        }
        
        for(int i=n-1; i>=0; i--){
            sum += nums[i];
            if(sum == x){
                ans = min(ans, n-i);
            }
            else if(map.find(x - sum) != map.end() && map[x - sum] < i){
                int s = n - i + map[x - sum] + 1;
                ans = min(ans, s);
            }
        }
        
        if(ans == INT_MAX) return -1;
        else return ans;
    }
};