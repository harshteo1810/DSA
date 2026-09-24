class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> pos;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    pos.push_back({i,j});
                }
            }
        }
        for(int i=0;i<pos.size();i++){
            int r = pos[i][0];
            int c = pos[i][1];
            //top;
            for(int j=0;j<n;j++){
                matrix[j][c] = 0;
            }
            //down
            for(int j=0;j<m;j++){
                matrix[r][j] = 0;
            }
        }
    }
};