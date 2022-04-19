class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> map;
        map[0]++;
        int curr = 0, ans = 0;
        
        for(int it:nums){
            curr += it;
            int r = curr % k;
            if(r < 0) r += k;
            
            if(map[r] != 0){
                ans += map[r];
            }
            map[r]++;
        }
        
        return ans;
    }
};