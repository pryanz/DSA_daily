class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> s(right + 1, true);
        s[0] = false;
        s[1] = false;
        vector<int> primes;
        for(int i = 2; i * i <= right; i++){
            if(s[i]){
                for(int j = i*i; j <= right; j+= i){
                    s[j] = false;
                }
            }
        }
        for(int i = left; i <= right; i++) if(s[i]) primes.push_back(i);
        if(primes.size() < 2) return {-1,-1};
        int minD = INT_MAX;
        vector<int> ans = {-1,-1};
        for(int i = 1; i < primes.size(); i++){
            if(primes[i] - primes[i-1] < minD){
                minD = primes[i] - primes[i-1];
                ans[0] = primes[i-1];
                ans[1] = primes[i];
            }
        }
        return ans;
    }
};