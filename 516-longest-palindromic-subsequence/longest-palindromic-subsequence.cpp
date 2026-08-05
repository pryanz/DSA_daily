class Solution {
public:
    int dp[1001][1001];
    int lcs(string & a, string & b, int i, int j){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(a[i] == b[j]) return dp[i][j] = 1 + lcs(a , b , i - 1, j - 1);
        return dp[i][j] = max(lcs(a,b, i-1, j), lcs(a, b, i, j - 1));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string b = "";
        for(int i = n-1; i >= 0; i--){
            b += s[i];
        }
        memset(dp, -1, sizeof(dp));
        return lcs(s, b, n - 1, n - 1);
    }
};