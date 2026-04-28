class Solution {
public:
    //would twow pointer work? It should ideally - nah s="()[]{}"

    bool isValid(string s) {
        unordered_map<char, char> mp;
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';

        int n = s.size();

        if(n%2 || !mp.count(s[0])) return false;

        stack<char> st;

        for(int i = 0; i < n; i++){
            if(mp.count(s[i]))
                st.push(s[i]);
            else{
                if(st.empty() || mp[st.top()] != s[i])
                    return false;
                st.pop();
            }
        }


        return st.empty();
    }
};
