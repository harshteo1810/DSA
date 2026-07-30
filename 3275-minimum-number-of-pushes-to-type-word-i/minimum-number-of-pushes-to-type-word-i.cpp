class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int tap;
        if(n<=8){
            return n;
        }
        else{
            int val  = n-8;
            tap = 8;
            int times=0;
            while(val>0){
                if(times<8){
                    tap+=2;
                }
                else if(times>=8 && times<=15){
                    tap+=3;
                }
                else{
                    tap+=4;
                }
                val--;
                times++;
            }
        }
        return tap;
    }
};