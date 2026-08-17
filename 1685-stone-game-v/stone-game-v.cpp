class Solution {
public:
    vector<vector<int>> dp;
    int solve(int s, int e, vector<int> &stones){
        if(s > e) return 0;
        if(dp[s][e] != -1) return dp[s][e];
        int r = 0;
        int l = 0;
        int ans = 0;
        for(int i = s; i <= e; i++) r+= stones[i];
        for(int i = s; i <=e ; i++){
            l += stones[i];
            r -= stones[i];
            if(l < r) ans = max(ans, l + solve(s, i, stones));
            if(l == r) ans = max(ans, l + max(solve(s, i, stones) , solve(i+1, e ,stones)));
            if(r < l) ans = max(ans, r + solve(i + 1, e, stones));
        }
        return dp[s][e] = ans;
    }
    int stoneGameV(vector<int>& stones) {
        int n = stones.size();
        dp.assign(n, vector<int>(n,-1));
        return solve(0, n - 1, stones);
    }
};