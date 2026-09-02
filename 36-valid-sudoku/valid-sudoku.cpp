class Solution {
public:
    bool func(int i,int j,vector<vector<char>>& board,int val){
        for(int k=0;k<9;k++){
            if(k!=i && val==board[k][j]){
                return false;
            }   
        }
        for(int k=0;k<9;k++){
            if(k!=j && val==board[i][k]){
                return false;
            }
        }
        int startRow = (i / 3) * 3;
        int startCol = (j / 3) * 3;

        for (int l = startRow; l < startRow + 3; l++) {
            for (int m = startCol; m < startCol + 3; m++) {
                if (board[l][m] == val && l!=i && m!=j) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    ans = func(i,j,board,board[i][j]);
                    if(ans==false){
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};