class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = (int)intervals.size();

        sort(intervals.begin(), intervals.end(), [](const vector<int>& i1, const vector<int>& i2){return i1[1] < i2[1];});

        int prev_end = INT_MIN;
        int ans = 0;

        for(auto& inter : intervals){
            if(inter[0] >= prev_end) prev_end = inter[1];
            else ans++;
        }

        return ans;
    }
};
