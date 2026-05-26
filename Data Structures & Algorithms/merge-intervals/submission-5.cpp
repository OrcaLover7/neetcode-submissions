class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int max_start = -1;

        for(auto& iv : intervals) max_start = max(max_start, iv[0]);

        vector<int> mp(max_start+1, 0);

        for(auto& iv : intervals){
            int start = iv[0];
            int end = iv[1];
            mp[start] = max(mp[start], end + 1);
        }

        vector<vector<int>> ans;
        int have = -1;
        int start = -1;

        for(int i = 0; i <= max_start; i++){
            if(mp[i] != 0){
                if(start == -1) start = i;
                have = max(mp[i] - 1, have);
            }

            if(have == i){
                ans.push_back({start, have});
                have = -1;
                start = -1;
            }
        }

        if(start != -1) ans.push_back({start, have});

        return ans;
    }
};
