class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int, int> freq;
        vector<int> uniq;

        for(int n : candidates){
            if(!freq[n]) uniq.push_back(n);
            freq[n]++;
        }

        vector<int> combo;
        vector<vector<int>> ans;

        bt(uniq, freq, 0, target, combo, ans);

        return ans;
    }

    void bt(vector<int>& uniq, unordered_map<int, int>& freq, int start, int target, vector<int>& combo, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(combo);
            return;
        }

        if(target < 0 || start >= (int)uniq.size()) return;

        int curr = uniq[start];

        if(freq[curr]){
            combo.push_back(curr);
            freq[curr]--;
            bt(uniq, freq, start, target - curr, combo, ans);
            freq[curr]++;
            combo.pop_back();
        }

        bt(uniq, freq, start+1, target, combo, ans);
    }
};
