class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = (int)intervals.size();

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });

        int prev_end = INT_MIN;
        int ans = 0;

        for(auto& inter : intervals){
            if(inter[0] >= prev_end) prev_end = inter[1];
            else ans++;
        }

        return ans;
    }
};
