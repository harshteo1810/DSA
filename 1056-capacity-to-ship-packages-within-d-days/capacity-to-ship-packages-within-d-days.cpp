class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid = (low+high)/2;
            int sum=0;
            int dys =0;
            for(int i:weights){
                sum += i;
                if(sum>mid){
                    dys++;
                    sum = i;
                }
            }
            dys++;
            if(dys>days){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};