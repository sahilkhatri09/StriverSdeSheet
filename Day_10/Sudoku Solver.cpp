class Solution {
    bool isValid(vector<vector<char>> &board ,int row,int col ,char k){
        for(int i=0;i<9;i++){
            if(board[i][col] == k || board[row][i] == k)return false;
            int nrow = row / 3;
            int ncol = col / 3;
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    if(board[nrow*3 + i][ncol*3 +j]==k)return false;
                }
            }
        }
        return true;
    }
    bool helper(vector<vector<char>> &board ,int row ,int col){
        if(row == 9)return true;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.')continue;
                for(char k='1' ;k<='9'; k++){
                    if(isValid(board,i,j,k)){
                        board[i][j] = k;
                        if(helper(board,0,0))return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board ,0 ,0);
    }
};