class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = (int)s.size();
        vector<int> last_seen(26, -1);
        vector<int> ans;

        for(int i = 0; i < n; i++) last_seen[s[i] - 'a'] = i;

        int start = 0, end = 0;

        for(int i = 0; i < n; i++){
            end = max(end, last_seen[s[i] - 'a']);
            if(i == end) {
                ans.push_back(end - start + 1);
                start = i+1;
            }
        }

        return ans;

    }
};
