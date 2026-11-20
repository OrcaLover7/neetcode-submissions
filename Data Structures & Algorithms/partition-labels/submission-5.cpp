class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = (int)s.size();
        unordered_map<char, int> last_seen;
        vector<int> ans;

        for(int i = 0; i < n; i++) last_seen[s[i]] = i;

        int start = 0, end = 0;

        while(start < n){
            for(int i = start; i <= end; i++){
                end = max(end, last_seen[s[i]]);
            }
            ans.push_back(end-start + 1);
            start = end+1;
            end = start;
        }

        return ans;
    }
};
