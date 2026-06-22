class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& i1, const vector<int>& i2) { return i1[1] < i2[1]; });

        int n = (int)intervals.size();
        vector<int> dp(n);
        int tmp = INT_MIN;
        
        for(int i = 0; i < n; i++){
            dp[i] = 1;

            for(int j = 0; j < i; j++) if(intervals[j][1] <= intervals[i][0]) dp[i] = max(dp[j] + 1, dp[i]);

            tmp = max(dp[i], tmp);
        }

        return n - tmp;
    }
};
