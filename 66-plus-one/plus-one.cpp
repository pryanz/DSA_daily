class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        int n = digits.size();
        for(int j = n-1; j >= 0; j--){
            digits[j] += c;
            c = digits[j]/10;
            digits[j] %= 10;
        }

        if(c) digits.insert(digits.begin(),c);

        return digits;
    }
};