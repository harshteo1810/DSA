class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            int k = target-nums[i];
            if(mpp.find(k)!=mpp.end()){
                return {i,mpp[k]};
            }
            else{
                mpp[nums[i]]=i;
            }
        }
        return {};
    }
};