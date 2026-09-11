class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newInterval) {
        int n = interval.size();
        vector<vector<int>> res;

        int i = 0;
        while(i < n && interval[i][1] < newInterval[0]){
            res.push_back({interval[i]});
            i++;
        }
        if(i == n){
            res.push_back({newInterval});
            return res;
        }

        if(interval[i][0] > newInterval[1]){
            res.push_back({newInterval});
            res.push_back({interval[i]});
        } else{
            res.push_back({min(interval[i][0], newInterval[0]),
                           max(interval[i][1], newInterval[1])});
        }
        i++;

        while(i < n && interval[i][0] <= res.back()[1]){
            vector<int> temp = {res.back()[0], max(interval[i][1], res.back()[1])};
            res.pop_back();
            res.push_back(temp);
            i++;
        }

        while(i < n){
            res.push_back({interval[i][0], interval[i][1]});
            i++;
        }

        return res;
    }
};