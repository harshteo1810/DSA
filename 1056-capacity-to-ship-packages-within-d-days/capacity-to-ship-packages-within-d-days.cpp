class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 1;
        int high = accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid = (low+high)/2;
            int sum=0;
            int dys =0;
            bool possible = true;
            for(int i:weights){
                sum += i;
                if(sum>mid){
                    dys++;
                    sum =0;
                    sum += i;
                    if(sum>mid){
                        possible = false;
                        break;
                    }
                }
            }
            dys++;
            if(!possible || dys>days){
                low = mid+1;
            }
            else if(dys<=days){
                high = mid-1;
            }
        }
        return low;
    }
};