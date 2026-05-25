class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = (int)intervals.size();

        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<int> start = intervals[0];

        for(int i = 1; i <= n; i++){
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
