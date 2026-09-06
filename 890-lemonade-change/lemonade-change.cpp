class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int c5 = 0,c10 = 0;
        if(bills[0]!=5){
            return false;
        }
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                c5++;
            }
            else if(bills[i]==10){
                c10++;
                if(c5>0){
                    c5--;
                }
                else{
                    return false;
                }
            }
            else{
                if(c10>0 && c5>0){
                    c10--;
                    c5--;
                }
                else if(c5>=3){
                    c5-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};