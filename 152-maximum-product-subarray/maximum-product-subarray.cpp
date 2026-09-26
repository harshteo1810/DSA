class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pref =1,suff=1;
        int maxi = -1e9;
        for(int i=0;i<n;i++){
            pref *= nums[i];
            suff *= nums[n-1-i];
            maxi = max(maxi,max(pref,suff));
            if(pref==0) pref = 1; 
            if(suff==0) suff = 1;
        }
        return maxi;
    }
};