class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string ans =strs[0];
        int n = strs.size();
        if(n==1){
            return ans;
        }
        for(int i=1;i<n;i++){
            string temp = "";
            for(int j = 0;j<min(ans.size(),strs[i].size());j++){
                if(ans[j]==strs[i][j]){
                    temp += ans[j];
                }
                else break;
            }
            ans = temp;
        }
        return ans;
    }
};