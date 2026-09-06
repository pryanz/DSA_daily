class Solution {
public:
    vector<vector<long long>> dp;
    long long solve(string & s, string &t, int i , int j){
        if(j >= t.size()){
            return 1;
        }
        if(i >= s.size()) return 0;
        if(s.size() - i < t.size() - j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] != t[j]){
            return dp[i][j] = solve(s, t, i+1, j);
            
        }
        return dp[i][j] = solve(s, t, i + 1, j + 1) + solve(s, t, i + 1, j);
    }

    int numDistinct(string s, string t) {
        dp.assign(s.size(), vector<long long>(t.size(),-1));
        return (int)solve(s, t, 0 , 0);

    }
};