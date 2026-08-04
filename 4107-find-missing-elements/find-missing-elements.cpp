class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int curr = nums[0];
        int i = 0;
        while(i < nums.size()){
            if(curr != nums[i]){
                ans.push_back(curr);
                curr++;
                continue;
            }
            i++;
            curr++;
        }
        return ans;
    }
};