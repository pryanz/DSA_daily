class Solution {
public:
    int score(vector<int>& nums, vector<vector<int>>& dp, int i , int j){
        if(i == j) return dp[i][j] = nums[i];
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = max(nums[i] - score(nums, dp, i + 1 , j), nums[j] - score(nums, dp, i , j - 1));
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return score(nums, dp, 0 , nums.size() - 1) >= 0;
    }
};