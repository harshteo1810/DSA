class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int minidx = 1e9;
        int maxi = -1e9;
        int n = nums.size();
        vector<int> minarr(n);
        minarr[n-1] = nums[n-1];
        int mini = nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(mini>nums[i]){
                mini = nums[i];
            }
            minarr[i]=mini;
        }
        for(int i=0;i<n;i++){
            if(maxi<nums[i]){
                maxi = nums[i];
            }
            mini = minarr[i];
            if(maxi-mini<=k){
                minidx = min(minidx,i);
            }
        }
        return minidx==1e9?-1:minidx;
    }
};