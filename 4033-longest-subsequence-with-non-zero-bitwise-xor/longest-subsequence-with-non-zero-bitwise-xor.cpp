class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor = 0;
        bool nonzero = 0;
        for(int & num : nums){
            totalXor ^= num;
            if(num != 0) nonzero = 1;
        }
        if(totalXor) return nums.size();
        else if(nonzero) return nums.size() - 1;
        return 0;
    }
};