class Solution {
public:
    int func(int i,int j, int n, int m,vector<vector<int>>& grid,vector<vector<int>> &dp){
        if(i==0 && j==0){
            return grid[i][j];
        }
        if(i<0 || j<0){
            return 1e9;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up = grid[i][j] + func(i-1,j,n,m,grid,dp);
        int left = grid[i][j] + func(i,j-1,n,m,grid,dp);
        return dp[i][j] = min(up + left , min(up,left));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return func(n-1,m-1,n,m,grid,dp);
    }
};