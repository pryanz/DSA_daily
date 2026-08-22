class Solution {
public:
    bool checkDivisibility(int n) {
        long long totalSum = 0;
        long long product = 1;
        int temp = n; 
        while(temp){
            int d = temp % 10;
            totalSum += d;
            product *= d;
            temp /= 10;
        }
        return (n % (totalSum + product)) == 0;
    }
};