class Solution {
public:
    //iska memo bhi nahi chalta
    int func(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>> &dp){
        if(j>i){
            return 1e9;
        }
        if(i==n-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down = func(i+1,j,n,triangle,dp);
        int diag = func(i+1,j+1,n,triangle,dp);
        return dp[i][j] = triangle[i][j] + min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        // return func(0,0,n,triangle,dp);
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                int up = dp[i+1][j];
                int diag = dp[i+1][j+1];
                dp[i][j] = triangle[i][j] + min(up,diag);
            }
        }
        return dp[0][0];
    }

};