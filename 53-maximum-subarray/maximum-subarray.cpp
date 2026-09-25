class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int maxsum = -1e9;
        for(int i=0;i<n;i++){
            if(sum+nums[i]<nums[i]){
                sum = nums[i];
            }
            else sum+=nums[i];
            maxsum = max(maxsum,sum);       
        }
        return maxsum;
    }
};