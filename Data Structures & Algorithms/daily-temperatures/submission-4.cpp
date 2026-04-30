class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<int> st;   
        vector<int> ans(temperatures.size(), 0);                                                                                                                        
        for (int i = 0; i < (int)temperatures.size(); i++) {      
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {                                                                    
                int j = st.top(); st.pop();                                                                                                      
                ans[j] = i - j;                                                                                                                  
            }                                                                                                                                    
            st.push(i);                                                                                                                          
        }
        return ans;
    }
};
