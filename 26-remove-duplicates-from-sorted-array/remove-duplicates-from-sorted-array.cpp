class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i=1;
        for(int j=0;j<n-1;j++){
            if(nums[j]!=nums[j+1]){
                nums[i] = nums[j+1];
                i++;
            }
        }
        return i;
    }
};