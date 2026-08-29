class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> mpp;
        vector<vector<int>>grps;
        int id = -1;
        for(int i = 0; i < sorted.size(); i++){
            if(i == 0 || sorted[i] - sorted[i-1] > limit){
                grps.push_back({});
                id++;
            }
            grps[id].push_back(sorted[i]);
            mpp[sorted[i]] = id;
        }

        vector<int> idx(grps.size(), 0);
        for(int i = 0; i < nums.size(); i++){
            int curr = mpp[nums[i]];
            nums[i] = grps[curr][idx[curr]];
            idx[curr]++;
        }
        return nums;
    }
};