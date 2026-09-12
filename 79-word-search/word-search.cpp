class Solution {
public:
    bool backtrack(vector<vector<char>>& board, string &word, int k, int i, int j, vector<vector<bool>> & vis){
        if(k == word.size()) return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
        if(vis[i][j] || board[i][j] != word[k]) return false;
        
        vis[i][j] = true;
        bool found =  backtrack(board, word, k + 1, i, j + 1, vis) || 
                      backtrack(board, word, k + 1, i, j - 1, vis) ||
                      backtrack(board, word, k + 1, i + 1, j, vis) ||
                      backtrack(board, word, k + 1, i - 1, j, vis);
        vis[i][j] = false;
        
        return found;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                vector<vector<bool>> vis(n,vector<bool>(m,false));
                if(backtrack(board, word, 0,i,j, vis)) return true;
            }
        }
        return false;
    }
};