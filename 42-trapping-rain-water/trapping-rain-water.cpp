class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        leftMax[0] = arr[0];
        rightMax[n-1] = arr[n-1];
        for(int i = 1; i < n; i++){
            leftMax[i] = max(leftMax[i-1],arr[i]);
            rightMax[n-1-i] = max(rightMax[n-i],arr[n-1-i]);
        }

        int total = 0;
        for(int i = 1; i < n-1; i++){
            if(arr[i] < leftMax[i - 1] && arr[i] < rightMax[i + 1]){
                total += min(leftMax[i-1] , rightMax[i + 1]) - arr[i];
            }
        }
        return total;
    }
};