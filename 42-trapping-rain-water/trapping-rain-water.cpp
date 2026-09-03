class Solution {
public:
    int trap(vector<int>& arr) {
        int i = 0; int j = arr.size() - 1;
        int l_max = arr[i]; int r_max = arr[j];
        int total = 0;

        while(i < j){
            if(l_max <= r_max){
                total += l_max - arr[i];
                i++;
                l_max = max(l_max, arr[i]);
            } else {
                total += r_max - arr[j];
                j--;
                r_max = max(r_max, arr[j]);
            }
        }
        return total;
    }
};