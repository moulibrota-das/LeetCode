class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0, ans = 0;        
        
        for(int i=n-k; i<n; i++){
            sum += cardPoints[i];
        }
        
        ans = max(sum,ans);
        int r = n;
        for(int i=0;i<k; i++){
            sum = sum - cardPoints[r-k] + cardPoints[r++ % n];
            ans = max(ans,sum);
        }
        return ans;
    }
};