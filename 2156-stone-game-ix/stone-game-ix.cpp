class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int div = 0;
        int oneRem = 0;
        int twoRem = 0;
        int n = stones.size();
        for(int & s : stones){
            if(s % 3 == 0) div++;
            else if(s % 3 == 1) oneRem++;
            else twoRem++;
        }
        if(div % 2 == 0){
            if(oneRem && twoRem) return true;
            else return false;
        }
        if(abs(oneRem - twoRem) > 2) return true;
        return false;
    }
};