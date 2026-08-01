class Solution {
public:
    bool func(int i,int tar,vector<int>&nums,vector<vector<int>> &dp){
        // if(tar<0 || i<0){
        //     return false;
        // }
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
        vector<vector<int>> dp(n,vector<int>(val+1,-1));
        return func(n-1,val,nums,dp);
    }
};