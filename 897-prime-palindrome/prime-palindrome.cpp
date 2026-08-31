class Solution {
public:
    bool findPrime(int no){
        if(no < 2) return false;
        if(no % 2 == 0) return no == 2;

        for(int i = 2; i*i <= no; i++){
            if(no % i == 0) return false;
        }
        return true;
    }

    int primePalindrome(int n) {
        if(n <= 2) return 2;
        if(n <= 3) return 3;
        if(n <= 5) return 5;
        if(n <= 7) return 7;
        if(n <= 11) return 11;

        for(int root = 1; ; root++){
            string s = to_string(root);
            string rev = s;
            rev.pop_back();
            reverse(rev.begin(), rev.end());
            int pal = stoi(s + rev);
            if(pal >= n && findPrime(pal)) return pal;
        }
        return -1;
    }
};