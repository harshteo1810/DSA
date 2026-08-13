class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i =0,j=n-1;
        while(i<j){
            char u = s[i];
            char v = s[j];
            if(isalnum(u) && isalnum(v)){
                u = tolower(u);
                v = tolower(v);
                if(u!=v){
                    return false;
                }
                i++;
                j--;
            }
            else if(!isalnum(u)){
                i++;
            }
            else{
                j--;
            }
        }
        return true; 
    }
};
