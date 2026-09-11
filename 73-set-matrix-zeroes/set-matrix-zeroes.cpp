class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        bool row = false;
        bool col = false;
        for(int i = 0; i < m; i++){
            if(mat[i][0] == 0) col = true;
        }

        for(int j = 0; j < n; j++) if(mat[0][j] == 0)row = true;

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(mat[i][j] == 0){
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(!mat[i][0] || !mat[0][j]) mat[i][j] = 0;
            }
        }
        if(row){
            for(int j = 0; j < n; j++) mat[0][j] = 0;
        }
        if(col) for(int i=0; i<m; i++) mat[i][0] = 0;
    }
};