class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int max_val = 0;

        for(const auto& interval : intervals) max_val = max(interval[0], max_val);

        vector<int> mp(max_val + 1, 0);

        for(const auto& interval : intervals){
            int start = interval[0];
            int end = interval[1];
            mp[start] = max(end + 1, mp[start]);
        }

        vector<vector<int>> ans;

        int have = -1;
        int start = -1;

        for(int i = 0; i < (int)mp.size(); i++){
            if(mp[i]){
                if(start == -1) start = i;
                have = max(have, mp[i] - 1);
            }

            if(have == i){
                ans.push_back({start, have});
                start = -1;
                have = -1;
            }
        }
        if(start != -1) ans.push_back({start, have});

        return ans;

    }

    
};
