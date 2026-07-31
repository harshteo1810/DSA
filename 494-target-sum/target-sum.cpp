// class Solution {
// public:
//     int func(int i,int k,int target,vector<int>&nums){
//         if (i < 0) return (k == target); // this base case handles all edge case like nums[i]=0 and target =0
//         int pos = func(i-1,k+nums[i],target,nums);
//         int neg = func(i-1,k-nums[i],target,nums);
//         return pos + neg;
//     }
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         vector<vector<int>(n,)> 
//         return func(n-1,0,target,nums);
//     }
// };

class Solution {
public:
    int func(int i, int target, vector<int>& nums,vector<vector<int>>& dp, int offset) {
        if (target > offset || target < -offset)
            return 0;
        if (i < 0)
            return target == 0;
        if (dp[i][target + offset] != -1)
            return dp[i][target + offset];
        int pos = func(i - 1, target - nums[i], nums, dp, offset);
        int neg = func(i - 1, target + nums[i], nums, dp, offset);
        return dp[i][target + offset] = pos + neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // Maximum absolute value the running sum can reach.
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int offset = sum;
        // If target is outside the possible range, no solution exists.
        if (abs(target) > sum)
            return 0;
        // sum can vary from -sum to +sum,
        // so create 2*sum + 1 columns.
        vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1));
        return func(n - 1, target, nums, dp, offset);
    }
};