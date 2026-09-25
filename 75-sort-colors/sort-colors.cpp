class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int c1=0;
        int c2=0;
        for(int i:nums){
            if(i==0){
                c1++;
            }
            else if(i==1){
                c2++;
            }
        }
        for(int i=0;i<n;i++){
            if(c1>0){nums[i]=0; c1--;}
            else if(c2>0){nums[i]=1; c2--;}
            else nums[i]=2;
        }
    }
};