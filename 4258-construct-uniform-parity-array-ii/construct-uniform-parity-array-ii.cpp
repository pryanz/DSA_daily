class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool allEven = true;
        int smallestEven = INT_MAX;
        int n = nums1.size();
        for(int i = 0; i< n; i++){
            if(nums1[i] % 2 == 1) allEven = false;
            else smallestEven = min(smallestEven, nums1[i]);
        }
        
        if(allEven || smallestEven == INT_MAX) return true;

        for(int i = 0; i < n; i++){
            if(nums1[i] % 2 == 1 && nums1[i] < smallestEven) return true;
        }
        return false;
    }
};