class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1] >= b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans = 0, k = truckSize;
        sort(boxTypes.begin(), boxTypes.end(), comp);
        
        for(auto it:boxTypes){
            if(k >= it[0]){
                ans += it[0] * it[1];
                k -= it[0];
            }
            else{
                ans += k * it[1];
                break;
            }
            
            if(k == 0) break;
        }
        
        return ans;
    }
};