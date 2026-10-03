class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans = 1e9;
        while(low<=high){
            int mid = (low+high)/2;
            int sum = 0;
            for(int i:nums){
                if(i%mid==0){
                    sum += i/mid;
                }
                else sum += i/mid + 1;
            }
            if(sum<=threshold){
                ans = min(ans,mid);
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};