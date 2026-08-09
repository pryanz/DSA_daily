class Solution {
public:
    int n;
    int solve(vector<vector<vector<int>>> &dp ,vector<int>& piles,int i, int m, int curr){
        if(i >= n) return 0;
        if(dp[i][m][curr] != -1) return dp[i][m][curr];
        int stones = 0;
        int score = INT_MAX;
        if(curr == 1) score = -1;
        for(int j = 1; j <= min(n-i, 2*m); j++){
            stones += piles[i + j - 1];
            if(curr == 1) score = max(score, stones + solve(dp, piles ,i+j , max(m,j), 0));
            else score = min(score,solve(dp,piles, i+j , max(m,j), 1));
        }
        return dp[i][m][curr] = score;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(n+1, vector<int>(2,-1)));
        return solve(dp, piles, 0 , 1, 1);
    }
};