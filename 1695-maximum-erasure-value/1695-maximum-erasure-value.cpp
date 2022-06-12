class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end  = 0;
        int sum = 0, ans = 0;
        unordered_map<int, int> freqMap;
        
        while(end < n) {
            int value = nums[end++];
            sum += value;
            freqMap[value]++;
            
            while(freqMap[value] > 1) {
                int left = nums[start++];
                freqMap[left]--;
                sum -= left;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};