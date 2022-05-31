class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = 1 << k;
        if(n > (s.size())) return false;
        vector<int> arr(n,0);
        int hash = 0, all = n-1;

        for(int i=0; i<s.size(); i++){
            hash = (hash << 1)&all | (s[i] - '0');
            if(i >= k-1 && arr[hash] == 0){
                arr[hash] = 1;
                n--;
                if(n == 0)
                    return true;
            }
        }
        
        return false;
    }
};