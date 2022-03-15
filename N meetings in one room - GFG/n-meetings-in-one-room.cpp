// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    bool static comp(pair<int, int> a, pair<int,int> b){
        if(a.second < b.second){
            return true;
        }
        else{
            return false;
        }
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> arr;
        for(int i = 0; i<n; i++){
            arr.push_back({start[i], end[i]});
        }
        
        sort(arr.begin(), arr.end(), comp);
        
        int last = 0, count = 0;
        
        for(auto it:arr){
            if(it.first > last){
                last = it.second;
                count++;
            }
        }
        
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends