class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // slow fast pointer technique of LL
        int slow = nums[0]; // initialise 
        int fast = nums[0]; // initialise

        //used do while because we don't want to encounter slow==fast at starting
        do{
            slow = nums[slow]; //increment by 1 pointer
            fast = nums[nums[fast]]; // increment by 2 pointer
        }
        while(slow!=fast);
        // once slow == fast occured we reinitialize slow to initial index value
        slow = nums[0];
        while(slow!=fast){
            slow = nums[slow]; //increment by 1 pointer
            fast = nums[fast]; //increment by 1 pointer
        }
        return slow;
    }
};