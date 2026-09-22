class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =1;
        int max_ele = nums[0];
        for(int i=1;i<nums.size();i++){
            if(count == 0){
                max_ele = nums[i];
                count++;
            }
            else if(nums[i]==max_ele){
                count++;
            }
            else{
                count--;
            }
        }
        return max_ele;
    }
};