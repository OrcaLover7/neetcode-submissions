class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combo;
        vector<vector<int>> ans;
        
        sort(candidates.begin(), candidates.end());

        bt(candidates, combo, target, ans, 0);

        return ans;
    }

    void bt(vector<int>& cand, vector<int>& combo, int target, vector<vector<int>>& ans, int start){
        if(!target){
            ans.push_back(combo);
            return;
        }
        
        for(int i = start; i < (int)cand.size(); i++){
            if(target - cand[i] < 0) break;
            if(i > start && cand[i] == cand[i-1]) continue;
            combo.push_back(cand[i]);
            bt(cand, combo, target-cand[i], ans, i+1);
            combo.pop_back();
        }
    }
};
