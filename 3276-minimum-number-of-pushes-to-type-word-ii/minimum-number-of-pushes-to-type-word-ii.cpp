class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        unordered_map<char,int> mp;
        for(char c:word){
            mp[c]++;
        }
        vector<pair<char, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;   // sort by frequency (descending)
        });
        unordered_map<char,int> mpp;
        int count = 1;
        for(auto c:v){
            if(count<9){
                if(mpp.find(c.first)==mpp.end()){
                    mpp[c.first]=1;
                    count++;
                }
            }
            else if(count>8 && count<17){
                if(mpp.find(c.first)==mpp.end()){
                    mpp[c.first]=2;
                    count++;
                }
            }
            else if(count>16 && count<25){
                if(mpp.find(c.first)==mpp.end()){
                    mpp[c.first]=3;
                    count++;
                }
            }
            else{
                if(mpp.find(c.first)==mpp.end()){
                    mpp[c.first]=4;
                    count++;
                }
            }
        }
        int sum =0;
        for(char c:word){
            sum+=mpp[c];
        }
        return sum;
    }
};