class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int content =0;
        int n = g.size();
        int m = s.size();
        int j =0,i=0;
        while(i<n && j<m){
            if(g[i]<=s[j]){
                content++;
                i++;
                j++;
            }
            else if(g[i]>s[j]){
                j++;
            }
            else{
                i++;
            }
        }
        return content;
    }
};