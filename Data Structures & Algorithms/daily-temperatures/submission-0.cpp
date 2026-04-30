class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<pair<int, int>> st;
        vector<int> ans;
        ans.resize(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); i++){

            int curr_temp = temperatures[i];

            if(!st.empty()){
                while(!st.empty() && st.top().second < curr_temp){
                    auto& [index, prev_temp] = st.top();
                    st.pop();
                    ans[index] = i-index;
                }
            }
            st.push({i, curr_temp});
        }

        return ans;
    }
};
