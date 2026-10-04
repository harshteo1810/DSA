class Solution {
public:
    int paint(vector<int>& arr, int board) {
        int painter = 1;
        int posboard = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] + posboard <= board) {
                posboard += arr[i];
            }
            else {
                painter++;
                posboard = arr[i];
            }
        }
        return painter;
    }
    int splitArray(vector<int>& arr, int k) {
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid = (high+low)/2;
            int painter = paint(arr, mid);
            if (painter > k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low; 
    }
};