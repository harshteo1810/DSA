class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const auto & a, const auto & b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0]<b[0];
        });
        int end = intervals[0][1];
        int start = intervals[0][0];
        vector<vector<int>> result;
        for(int i=1;i<intervals.size();i++){
            if(end<intervals[i][0]){
                result.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else if(end<intervals[i][1]){
                end = intervals[i][1];
            }
        }
        result.push_back({start,end});
        return result;
    }
};