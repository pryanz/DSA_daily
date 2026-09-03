class Solution {
public:
    int solveBlock(int i, int j){
        if(i < 3){
            if(j < 3) return 0;
            else if(j < 6) return 1;
            else return 2;
        }else if(i < 6){
            if(j < 3) return 3;
            else if(j < 6) return 4;
            else return 5;
        }else {
            if(j < 3) return 6;
            else if(j < 6) return 7;
            else return 8;
        }
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9,vector<bool>(10));
        vector<vector<bool>> col(9,vector<bool>(10));
        vector<vector<bool>> block(9,vector<bool>(10));

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                int val = board[i][j] - '0';
                int b = solveBlock(i,j);

                if(row[i][val]) return false;
                if(col[j][val]) return false;
                if(block[b][val]) return false;
                
                row[i][val] = true;
                col[j][val] = true;
                block[b][val] = true;
            }
        }

        return true;
    }
};