class Solution {
public:
    int divide(vector<int>& arr, int maxSplit) {
        int split = 1;
        int possSplit = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] + possSplit <= maxSplit) {
                possSplit += arr[i];
            }
            else {
                split++;
                possSplit = arr[i];
            }
        }
        return split;
    }
    int splitArray(vector<int>& arr, int k) {
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid = (high+low)/2;
            int split = divide(arr, mid);
            if (split > k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low; 
    }
};