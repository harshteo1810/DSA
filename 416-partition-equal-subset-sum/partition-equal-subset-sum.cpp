class Solution {
public:
    bool func(int i,int tar,vector<int>&nums,vector<vector<int>> &dp){
        if(tar==0){
            return true;
        }
        if(i==0){
            return tar==nums[i];
        }
        if(dp[i][tar]!=-1){
            return dp[i][tar];
        }
        bool pick = false;
        if(tar>=nums[i]){
            pick = func(i-1,tar-nums[i],nums,dp);
        }
        bool non = func(i-1,tar,nums,dp);
        return dp[i][tar] = pick || non;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum =0;
        int n = nums.size();
        for(int i:nums){
            totalSum += i;
        }
        if(totalSum%2!=0){
            return false;
        }
        int val = totalSum/2;
        vector<vector<int>> dp(n,vector<int>(val+1,0));
        if(nums[0]<=val){
            dp[0][nums[0]] = 1;
        }
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=val;j++){
                int non = dp[i-1][j];
                int pick = 0;
                if(nums[i]<=j){
                    pick = dp[i-1][j-nums[i]];
                }
                dp[i][j] = pick || non;
            }
        }
        return dp[n-1][val];
        // return func(n-1,val,nums,dp);
    }
};