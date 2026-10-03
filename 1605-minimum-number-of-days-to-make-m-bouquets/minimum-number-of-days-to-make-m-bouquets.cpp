class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int n = bloomDay.size();
        int ans;
        if(1ll*m*k>n){
            return -1;
        }
        while(low<=high){
            int mid = (low+high)/2;
            int bq = 0;
            int pk = 0;
            for(int i:bloomDay){
                if(i<=mid){
                    pk++;
                    if(pk==k){
                        bq++;
                        pk = 0;
                    }
                }else{
                    pk = 0;
                }
            }
            if(bq>=m){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};