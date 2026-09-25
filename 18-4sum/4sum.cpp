class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> uq;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                unordered_set<long long> st;
                for (int k = j + 1; k < n; k++) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long req = 1LL * target - sum;
                    if (st.find(req) != st.end()) {
                        vector<int> temp = {nums[i],nums[j],nums[k],(int)req};
                        sort(temp.begin(), temp.end());
                        uq.insert(temp);
                    }
                    st.insert(nums[k]);
                }
            }
        }
        return vector<vector<int>>(uq.begin(), uq.end());
    }
};