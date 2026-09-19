class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i:nums){
            mpp[i]++;
            if(mpp[i]>1){
                return i;
            }
        }
        return 0;
    }
};