class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==1){
            int ans = -1;
            unordered_map<int,int> mpp;
            for(int x:nums){
                mpp[x]++;
            }
            for(auto p:mpp){
                if(p.second==1){
                    ans = max(ans,p.first);
                }
            }
            return ans;
        }
        else if(k==n){
            return *max_element(nums.begin(), nums.end());
        }
        int fq1=0,fq2=0;
        for(int i=0;i<k;i++){
            if(nums[0]==nums[i]){
                fq1++;
            }
            else if(nums[n-1]==nums[i]){
                fq2++;
            }
        }
        for(int i=k;i<n;i++){
            if(nums[0]==nums[i]){
                fq1++;
            }
            else if(nums[n-1]==nums[i]){
                fq2++;
            }
        }
        if(fq1==1 && fq2==1){
            return max(nums[0],nums[n-1]);
        }
        else if(fq2==1){
            return nums[n-1];
        }
        else if(fq1==1){
            return nums[0];
        }
        return -1;
    }
};