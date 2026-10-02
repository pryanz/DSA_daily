class Solution {
public:
    void bt(int & n, string s, int i, int j, vector<string> & ans){
        if(i > n || j > n || j > i) return;
        if(i == n && j == n){
            ans.push_back(s);
            return;
        }
        bt(n, s + "(", i + 1, j, ans);
        bt(n, s + ")", i, j + 1, ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        bt(n, "", 0 , 0 ,ans);
        return ans;
    }
};