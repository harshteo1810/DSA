class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = 1e9;

        while (low <= high) {

            // // Entire range is sorted
            // if (nums[low] <= nums[high]) {
            //     ans = min(ans, nums[low]);
            //     break;
            // }

            int mid = low + (high - low) / 2;

            // Left half is sorted
            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            // Right half is sorted
            else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};