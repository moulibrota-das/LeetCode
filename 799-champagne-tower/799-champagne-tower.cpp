class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> arr(101,vector<double>(101));
        arr[0][0] = (double)poured;
        
        for(int i=0; i<=query_row; i++){
            for(int j=0; j<=i; j++){
                double over = (arr[i][j] - 1) / 2;
                
                if(over > 0){
                    arr[i+1][j] += over;
                    arr[i+1][j+1] += over;
                }
            }
        }
        
        return min(1.0,arr[query_row][query_glass]);
    }
};