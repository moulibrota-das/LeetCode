class NumMatrix {
public:
    vector<vector<int>> arr;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m =matrix[0].size();
        arr = vector<vector<int>>(n+1, vector<int>(m+1,0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                arr[i][j] = arr[i][j-1] + matrix[i-1][j-1] + arr[i-1][j] - arr[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return arr[row2+1][col2+1] - arr[row1][col2+1] - arr[row2+1][col1] + arr[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */