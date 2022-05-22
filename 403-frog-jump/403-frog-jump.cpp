class Solution {
public:
    bool solve(int i, int jump, vector<int>& stones,map<int,int>& map,vector<vector<long long>>& dp){
        if(i == stones.size() - 1) return true;
        if(dp[i][jump] != -1) return dp[i][jump];
        bool p =false,q=false,r=false;
        
        if(jump > 1 && map.find(stones[i] + jump -1) != map.end())
            p = solve(map[stones[i] + jump - 1], jump-1, stones, map,dp);
        
        if(jump > 0 && map.find(stones[i] + jump) != map.end())
            q = solve(map[stones[i] + jump], jump, stones, map,dp);
        
        if(map.find(stones[i] + jump + 1) != map.end())
            r = solve(map[stones[i] + jump + 1], jump+1, stones, map,dp);
        
        return dp[i][jump] = p | q | r;
    }
    bool canCross(vector<int>& stones) {
        vector<vector<long long>> dp(stones.size(), vector<long long>(stones.size() + 1,-1));
        map<int,int> map;
        for(int i=0; i<stones.size(); i++){
            map[stones[i]] = i;
        }
        
        return solve(0,0,stones,map,dp);
    }
};