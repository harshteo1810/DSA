class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int x:nums){
            mpp[x]++;
        }
        for(auto &p:mpp){
            if(p.second>1){
                return true;
            }
        }
        return false;
    }
};