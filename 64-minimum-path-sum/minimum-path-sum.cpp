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
        int up = func(i-1,j,n,m,grid,dp);
        int left =  func(i,j-1,n,m,grid,dp);
        return dp[i][j] = grid[i][j] + min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0] = grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    continue;
                }
                int down = 1e9;
                int right = 1e9;
                if(i!=0){
                    down  = dp[i-1][j];
                }
                if(j!=0){
                    right = dp[i][j-1];
                }
                dp[i][j] = grid[i][j] + min(down,right);
            }
        }
        return dp[n-1][m-1];
        // return func(n-1,m-1,n,m,grid,dp);
    }
};