class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        for(int i = 0; i < n; i++){
            int j = i + 1;
            int k = n-1;
            while(j < k){
                int sumVal = nums[i] + nums[j] + nums[k];
                if(sumVal == 0){
                    ans.insert({nums[i],nums[j],nums[k]});
                    j++;
                } else if(sumVal > 0) k--;
                else j++;
            }
        }

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};