class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;

        int n = (int)s.size();
        if(n == 1) return 1;

        unordered_set<string> st;
        for(int i = 1; i <= 26; i++) st.insert(to_string(i));

        int a = 1, b = 1;

        for(int i = 2; i <= n; i++){
            string single = "";
            string doub = "";

            single += s[i-1];
            doub += s[i-2];
            doub += s[i-1];

            auto p1 = st.count(single);
            auto p2 = st.count(doub);

            int c = 0;
            
            if(p1 && p2) c = a + b;
            else if(p1 && !p2) c = b;
            else if(!p1 && p2) c = a;
            else c = 0;

            a = b;
            b = c;
        }

        return b;
    }
};
