class Solution {
public:
    int func(int i,int j,int k,int n,int m,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        if(j<0 || j>=m || k<0 || k>=m){
            return -1e8;
        }
        if(i==n-1){
            if(j==k){
                return grid[i][j];
            }
            else{
                return grid[i][j] + grid[i][k];
            }
        }
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        int maxi =0;
        for(int d1=-1;d1<2;d1++){
            for(int d2=-1;d2<2;d2++){
                if(j==k){
                    maxi = max(maxi,grid[i][j]+func(i+1,d1+j,d2+k,n,m,grid,dp));
                }
                else{
                    maxi = max(maxi,grid[i][j] + grid[i][k] + func(i+1,d1+j,d2+k,n,m,grid,dp));
                }
            }
        }
        return dp[i][j][k] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(
                m,
                vector<int>(m,-1)
            )
        );
       return func(0,0,m-1,n,m,grid,dp);
    }
};