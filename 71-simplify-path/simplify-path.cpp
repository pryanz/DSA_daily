class Solution {
public:
    string simplifyPath(string path) {
        vector<string> s;
        string curr = "";
        path += "/";
        for(char & ch : path){
            if(ch == '/'){
                if(curr == ".."){
                    if(!s.empty()) s.pop_back();
                }
                else if(curr != "." && curr != "") s.push_back(curr);
                curr = "";
            }
            else curr += ch;
        }
        string ans;
        for(int i = 0; i < s.size(); i++){
            ans += s[i];
            if(i != s.size() - 1) ans += "/";
        }
        return "/" + ans;
    }
};