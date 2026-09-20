class Solution {
public:
    int reverseDegree(string s) {
        long long ans = 0;
        int i = 1;
        for(char & c : s){
            ans += i * ('z' - c + 1);
            i++;
        }
        return ans;
    }
};