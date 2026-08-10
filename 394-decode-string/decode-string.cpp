class Solution {
public:
    string decodeString(string s) {
        int curr = 0;
        vector<int> ist;
        vector<string> sst;
        for(char & ch : s){
            if(ch - '0' >= 0 && ch - '0' <= 9){
                curr = (curr * 10) + (ch - '0');
            }
            else if(ch == '['){
                ist.push_back(curr);
                curr = 0;
                string temp = "";
                temp += ch;
                sst.push_back(temp);
            } else if(ch == ']'){
                string temp = "";
                while(!sst.empty() && sst.back() != "["){
                    temp = sst.back() + temp;
                    sst.pop_back();
                }
                sst.pop_back();
                int num = ist.back();
                ist.pop_back();
                string repeated = "";
                for(int i = 0; i < num; i++) repeated += temp;
                sst.push_back(repeated);
            }
            else{
                string temp = "";
                temp += ch;
                sst.push_back(temp);
            }
        }
        string ans = "";
        for(string & s : sst){
            if(s == "[") continue;
            ans += s;
        }
        return ans;
    }
};