class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        vector<int> start = intervals[0];

        for(int i = 1; i < (int)intervals.size(); i++){
            if(start[1] >= intervals[i][0]) start[1] = max(start[1], intervals[i][1]);
            else{
                ans.push_back(start);
                start = intervals[i];
            }
        }

        ans.push_back(start);

        return ans;
    }
};
