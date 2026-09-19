class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<int> res;
        for(int i:nums){
            mpp[i]++;
            if(mpp[i]==2){
                res.push_back(i);
            }
        }
        return res;
    }
};