class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> map;
        int sum = 0,count = 0;
        map[0]++;
        
        for(auto it : nums){
            sum += it;
            if(map[sum-k] > 0){
                count = count + map[sum - k];
            }
            map[sum]++;
        }
        return count;
    }
};