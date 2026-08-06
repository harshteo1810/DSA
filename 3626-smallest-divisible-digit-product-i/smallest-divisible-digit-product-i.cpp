class Solution {
public:
    int smallestNumber(int n, int t) {
        
        for(int i=n;i<n+10;i++){
            int temp = i;
            int val = 1;
            while(temp>0){
                val = val*(temp%10);
                temp = temp/10;
            }
            if(val%t==0){
                return i;
            }
        }
        return 0;
    }
};