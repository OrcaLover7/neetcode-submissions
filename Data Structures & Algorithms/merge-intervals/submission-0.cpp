class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        sort(intervals.begin(), intervals.end());

        auto start = intervals[0];

        for(int i = 0; i < (int)intervals.size(); i++){
            if(start[1] >= intervals[i][0]){
                start = {start[0], max(start[1], intervals[i][1])};
            }
            else{
                ans.push_back(start);
                start = intervals[i];
            }
        }

        ans.push_back(start);

        return ans;
    }
};
