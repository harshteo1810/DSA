class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans(rowIndex+1);
        for(int i=0;i<rowIndex+1;i++){
            for(int j=0;j<=i;j++){
                if(i>1 && j>0 && j!=i){
                    int a = ans[i-1][j-1];
                    int b = ans[i-1][j];
                    ans[i].push_back(a+b);
                }   
                else ans[i].push_back(1);
            }
        }
        vector<int> res;
        for(int i=0;i<=rowIndex;i++){
            res.push_back(ans[rowIndex][i]);
        }
        return res;
    }
};