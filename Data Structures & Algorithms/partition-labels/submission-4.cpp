class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last_seen;

        int n = (int)s.size();

        for(int i = 0; i < n; i++) last_seen[s[i]] = i;

        int end = 0;
        int start = 0;
        vector<int> ans;

        for(int i = 0; i < n; i++){
            end = max(end, last_seen[s[i]]);
            if(i == end){
                ans.push_back(end - start + 1);
                start = end+1;
            }
        }

        return ans;
    }
};
