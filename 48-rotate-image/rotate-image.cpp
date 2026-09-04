class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int k = n - 1;
        for(int i = 0; i < n / 2; i++){
            for(int j = i; j < k - i; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[k - j][i];
                matrix[k - j][i] = matrix[k - i][k - j];
                matrix[k - i][k-j] = matrix[j][k-i];
                matrix[j][k-i] = temp;
            }
        }
    }
};