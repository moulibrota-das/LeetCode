class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return (a[1] < b[1]);
    }
    
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comp);
        int count = 0, day = 0;
        priority_queue<int> pq;
        
        for(auto it:courses){
            if(day + it[0] <= it[1]){
                day += it[0];
                pq.push(it[0]);
            }
            else if(!pq.empty() && it[0] <= pq.top()){
                day = day - pq.top() + it[0];
                pq.pop();
                pq.push(it[0]);
            }
        }
        
        return pq.size();
    }
};