class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half1 = 0;
        int half2 = 0;
        int diff = 0;
        for(int i = 0; i < n; i++){
            if(num[i] == '?'){
                if(i < n/2) half1++;
                else half2++;
            }
            else{
                if(i < n/2) diff += num[i] - '0';
                else diff -= num[i] - '0';
            }
        }
        if(abs(half1 - half2) % 2 == 1) return true;
        return diff != -((half1 - half2)/2)*9;
    }
};