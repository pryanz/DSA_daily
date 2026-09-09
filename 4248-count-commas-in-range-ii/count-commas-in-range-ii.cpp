class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        if(n < 1000) return ans;
        if(n < 1000000){
            return n - 999LL;
        }
        ans += 999000;
        if(n < 1000000000) return 2LL*(n - 999999LL) + ans;
        ans += 2LL*999000000;

        if(n < 1000000000000) return 3LL*(n - 999999999LL) + ans;
        ans += 3LL*999000000000;

        if(n < 1000000000000000) return 4LL*(n - 999999999999LL) + ans;

        ans += 4LL*999000000000000;
        return ans + 5;
    }
};