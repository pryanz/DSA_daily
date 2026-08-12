class Solution {
public:
    int calculate(string s) {
        long long n = 0;
        stack<long long> num;
        char op = '+';
        for(char & ch: s){
            if(ch == ' ') continue;
            if(ch - '0' >= 0 && ch - '0' <= 9){
                n = n * 10 + (ch - '0');
            }else {
                if(op == '+') num.push(n);
                else if(op == '-') num.push(-n);
                else if(op == '*'){
                    long long temp = num.top();
                    num.pop();
                    num.push(temp * n);
                }
                else if(op == '/'){
                    long long temp = num.top();
                    num.pop();
                    num.push(temp/n);
                }
                n = 0;
                op = ch;
            }
        }
        if(op == '+') num.push(n);
        else if(op == '-') num.push(-n);
        else if(op == '*'){
            long long temp = num.top();
            num.pop();
            num.push(temp * n);
        }
        else {
            long long temp = num.top();
            num.pop();
            num.push(temp/n);
        }
        long long ans = 0;
        while(!num.empty()){
            ans += num.top();
            num.pop();
        }
        return (int)ans;
    }
};