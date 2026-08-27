class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int i:nums){
            mpp[i]++;
        }
        vector<int> res;
        for(int i=0;i<k;i++){
            int maxi = 0;
            int ele=0;
            for(auto &p:mpp){
                if(p.second>maxi){
                    maxi = p.second;
                    ele = p.first;
                }
            }
            mpp.erase(ele);
            res.push_back(ele);
        }
        return res;
    }
};