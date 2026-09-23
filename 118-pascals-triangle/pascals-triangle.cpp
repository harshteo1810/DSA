class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i=0;i<numRows;i++){
            for(int j=0;j<=i;j++){
                if(i>1 && j>0 && j!=i){
                    int a = ans[i-1][j-1];
                    int b = ans[i-1][j];
                    ans[i].push_back(a+b);
                }   
                else ans[i].push_back(1);
            }
        }
        return ans;
    }
};