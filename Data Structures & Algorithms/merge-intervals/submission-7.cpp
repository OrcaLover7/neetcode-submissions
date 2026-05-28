class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int max_start = -1;

        for(auto iv : intervals) max_start = max(max_start, iv[0]);

        vector<int> mp(max_start+1, 0);

        for(auto iv : intervals){
            int start = iv[0];
            int end = iv[1];

            mp[start] = max(mp[start], end+1);
        }

        vector<vector<int>> ans;
        int start = -1;
        int have = -1;

        for(int i = 0; i <= max_start; i++){
            if(mp[i]){
                if(start == -1) start = i;
                have = max(have, mp[i]-1);
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
