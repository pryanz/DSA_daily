class Solution {
public:
    bool check(int n, int t){
        int product = 1;
        while(n > 0){
            int d = n % 10;
            n /= 10;
            product *= d;
        }
        return product % t == 0;
    }
    int smallestNumber(int n, int t) {
        while(!check(n, t)){
            n += 1;
        }
        return n;
    }
};