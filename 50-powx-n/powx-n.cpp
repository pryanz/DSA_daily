class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0;

        double base = x;
        long long exp = n;
        if(exp < 0){
            base = 1.0/base;
            exp = -exp;
        }
        double result = 1.0;
        while(exp > 0){
            if(exp % 2 == 1){
                result *= base;
            }
            base *= base;
            exp /= 2;
        }

        return result;
    }
};