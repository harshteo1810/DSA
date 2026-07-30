class Solution {
public:
    int func(int i,int j, int m ,int n,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
        if(i>=m || j>=n){
            return 0;
        }
        if(i==m-1 && j==n-1){
            if(obstacleGrid[i][j]==0){
                return 1;
            }
            return 0;
        }
        if(dp[i][j]!= -1){
            return dp[i][j];
        }
        int down = 0;
        int right = 0;
        if(obstacleGrid[i][j]==0){
            down = func(i+1,j,m,n,obstacleGrid,dp);
            right = func(i,j+1,m,n,obstacleGrid,dp);
        }
        return dp[i][j] = down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return func(0,0,m,n,obstacleGrid,dp);
    }
};