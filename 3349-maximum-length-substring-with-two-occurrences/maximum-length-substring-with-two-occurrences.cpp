class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int j =0;
        int ans = 0;
        unordered_map<char,int> mpp;
        for(int i=0;i<n;i++){
            if(mpp.find(s[i])!=mpp.end()){
                mpp[s[i]]++;
                while(mpp[s[i]]>2){
                    mpp[s[j]]--;
                    if(mpp[s[j]]==0){
                        mpp.erase(s[j]);
                    }
                    j++;
                }
            }else{
                mpp[s[i]]++;
            }
            if(mpp.size()<=i-j+1){
                ans = max(ans,i-j+1);
            }
        }
        return ans;
    }
};