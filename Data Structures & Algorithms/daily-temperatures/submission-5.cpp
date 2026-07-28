class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = (int)temperatures.size();
        vector<int> results(n, 0);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() and temperatures[st.top()] < temperatures[i]){
                results[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }


        return results;

    }
};
