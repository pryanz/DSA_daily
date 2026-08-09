class Solution {
public:
    int dp[101][101];
    bool solve(string & s1, string & s2 , string & s3, int i , int j, int k){
        if(i >= s1.size() && j >= s2.size()) return true;
        else if(j >= s2.size()) {
            if(s1[i] == s3[k]) return solve(s1, s2, s3, i + 1, j, k + 1);
            return false;
        }
        else if(i >= s1.size()){
            if(s2[j] == s3[k]) return solve(s1, s2, s3, i, j + 1, k + 1);
            return false;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        bool ans = false;
        if(s1[i] == s3[k]) ans |= solve(s1, s2 ,s3 , i + 1, j, k + 1);
        if(s2[j] == s3[k]) ans |= solve(s1, s2, s3, i, j + 1, k + 1);
        return dp[i][j] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        memset(dp, -1 , sizeof(dp));
        return solve(s1, s2, s3, 0, 0 , 0);
    }
};