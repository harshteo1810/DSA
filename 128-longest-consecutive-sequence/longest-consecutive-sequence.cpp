class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        for(int i:nums){
            st.insert(i);
        }
        int maxi = 0;
        for(int i:st){
            if(st.find(i-1)!=st.end()){
                continue;
            }
            else{
                int curr =i;
                int len = 1;
                while(st.find(curr+1)!=st.end()){
                    len++;
                    curr++;
                }
                maxi = max(len,maxi);
            }
        }
        return maxi;
    }
};