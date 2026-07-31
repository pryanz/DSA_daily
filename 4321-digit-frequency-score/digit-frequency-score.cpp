class Solution {
public:
    int digitFrequencyScore(int n) {
        string s = to_string(n);
        vector<int> freq(10);
        for(char & ch : s){
            freq[ch - '0']++;
        }
        long long score = 0;
        for(int i = 0; i < 10; i++){
            score += freq[i]*i;
        }
        return score;
    }
};