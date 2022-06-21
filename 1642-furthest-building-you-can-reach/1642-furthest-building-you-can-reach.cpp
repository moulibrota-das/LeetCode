class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int index = 0;
        priority_queue<int> pq;
        
        while(index < n-1){
            if(heights[index+1] > heights[index]){
                int diff = heights[index+1] - heights[index];
                
                if(bricks >= diff){
                    bricks -= diff;
                    pq.push(diff);
                }
                else if(ladders > 0){
                    if(!pq.empty() && pq.top() > diff){
                        bricks += pq.top();
                        pq.pop();
                        pq.push(diff);
                        bricks -= diff;
                    }
                    ladders--;
                }
                else break;
            
            }
            index++;
        }
        return index;
    }
};