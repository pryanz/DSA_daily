class Solution {
public:
    string toReverseString(const vector<int> & arr){
        ostringstream oss;
        for(auto it = arr.rbegin(); it != arr.rend(); ++it){
            oss << *it;
        }
        return oss.str();
    }

    string build_end(long long req, int size){
        vector<int> arr;
        for(int i = 9; i > 1; i--){
            while(req % i == 0){
                req /= i;
                arr.push_back(i);
            }
        }
        while(arr.size() < size) arr.push_back(1);

        return toReverseString(arr);
    }
    string smallestNumber(string num, long long t) {
        int n = num.size();
        long long curr = t;

        int d[] = {2,3,5,7};
        for(int k = 0; k < 4; k++){
            while(curr % d[k] == 0){
                curr /= d[k];
            }
        }
        if(curr != 1) return "-1";

        vector<long long> rem(n+1, 0);
        rem[0] = t;
        int z = -1;
        for(int i = 0; i < n; i++){
            if(num[i] == '0'){
                z = i;
                break;
            }
            rem[i+1] = rem[i] / (gcd(rem[i], num[i] - '0'));
        }
        if (rem[n] == 1) return num;

        int start = n-1;
        if(z != -1) start = z;

        for(int i = start; i > -1; i--){
            int end_size = n - i - 1;
            for(int d = (num[i] - '0') + 1; d < 10; d++){
                string last = build_end(rem[i] / gcd(rem[i],d), end_size);
                if(last.size() == end_size) return num.substr(0,i) + to_string(d) + last;
            }
        }

        return build_end(t, n + 1);
    }
};