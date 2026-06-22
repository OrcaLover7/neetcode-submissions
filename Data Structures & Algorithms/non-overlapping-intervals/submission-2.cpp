class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& i1, const vector<int>& i2) { return i1[1] < i2[1]; });

        int ans = 0, prev_end = intervals[0][1];

        for(int i = 1; i < (int)intervals.size(); i++){
            if(intervals[i][0] >= prev_end) prev_end = intervals[i][1];
            else ans++;
        }

        return ans;
    }
};
