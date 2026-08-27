class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        for(auto&s:strs){
            map<char,int> mp;
            string word ="";
            for(char c:s){
                mp[c]++;
            }
            for(auto p:mp){
                word += p.first;             
                word += (char)('0' + p.second);   
            }
            mpp[word].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto &p:mpp){
            ans.push_back(p.second);
        }
        return ans;
    }
};