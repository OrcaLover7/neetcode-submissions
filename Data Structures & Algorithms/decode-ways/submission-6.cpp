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
            string sin = "";
            string doub = "";

            sin += s[i-1];
            doub = doub + s[i-2] + s[i-1];

            bool b1 = st.count(sin);
            bool b2 = st.count(doub);

            int c = 0;

            if(b1 && b2) c = a + b;
            else if(b1 && !b2) c = b;
            else if(!b1 && b2 ) c = a;
            else c = 0;

            a = b;
            b = c;
        }

        return b;
    }
};
