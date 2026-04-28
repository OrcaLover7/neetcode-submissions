class Solution {
public:
    //would twow pointer work? It should ideally - nah s="()[]{}"

    bool isleft(char c){
        return (c == '{' || c == '[' || c == '(');
    }
    bool isValid(string s) {
        unordered_map<char, char> mp;
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';

        int n = s.size();

        if(n%2) return false;

        stack<char> st;

        for(int i = 0; i < n; i++){
            if(isleft(s[i])){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                char top = st.top();
                if(mp[top] != s[i])
                    return false;
                st.pop();
            }
        }


        return st.empty();
    }
};
