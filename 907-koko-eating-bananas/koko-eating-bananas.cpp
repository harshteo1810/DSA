class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = 1e9;
        while(low<=high){
            int mid = (low+high)/2;
            long long time = 0;
            for(int i:piles){
                if(i%mid==0){
                    time += i/mid;
                }
                else {
                    time += i/mid+1;
                }
            }
            if(time<=h){
                ans = min(ans,mid);
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};