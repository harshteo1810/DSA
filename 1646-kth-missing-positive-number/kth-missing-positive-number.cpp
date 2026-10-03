class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //brute force
        for(int i:arr){
            if(i<=k){
                k++;
            }
            else {
                break;
            }
        }
        return k;
    }
};