class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int mini = n;
        for(int i=0;i<n;i++){
            // if(mpp.find(nums[i])!=mpp.end()){
            //     mini = min(mini,i-mpp[nums[i]]);
            // }
            // mpp[nums[i]]
            // else{
                string s = to_string(nums[i]);
                reverse(s.begin(),s.end());
                int ans = stoi(s);
                if(mpp.find(nums[i])!=mpp.end()){
                    mini = min(mini,i-mpp[nums[i]]);
                }
                
                mpp[ans]=i;
            // 
        }
        
        return mini==n?-1:mini;
    }
};