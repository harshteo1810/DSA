class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        int suff = 1;
        prefix[0] = 1;
        for(int i=0;i<n-1;i++){
            prefix[i+1] = nums[i]*prefix[i];
        }
        vector<int> res(n);
        for(int i=n-1;i>=0;i--){
            res[i] = prefix[i]*suff;
            suff *= nums[i];
        }
        return res;
    }
};