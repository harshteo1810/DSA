class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int i:nums){
            mpp[i]++;
        }
        vector<pair<int,int>> ans;
        for(auto &p:mpp){
            ans.push_back({p.first,p.second});
        }
        sort(ans.begin(),ans.end(),[](const auto& a, const auto& b) {
            return a.second >b.second;
        });
        vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back(ans[i].first);
        }
        return res;
    }
};