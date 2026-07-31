class Solution {
public:
    int func(int i,int k,int target,vector<int>&nums){
        if (i < 0) return (k == target);
        int pos = func(i-1,k+nums[i],target,nums);
        int neg = func(i-1,k-nums[i],target,nums);
        return pos + neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return func(n-1,0,target,nums);
    }
};