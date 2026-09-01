class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN || x == INT_MAX) return 0;
        long long rev = 0;
        bool neg = false;
        if(x < 0){
            neg = true;
            x *= -1;
        }
        while(x){
            int d = x % 10;
            x /= 10;
            if(rev > INT_MAX/10 || rev == INT_MAX) return 0;
            rev = (rev * 10) + d;
        }
        if(neg) return -rev;
        return rev;
    }
};