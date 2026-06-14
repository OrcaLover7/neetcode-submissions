class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;

        int n = (int)s.size();

        if(n == 1) return 1;

        int a = 1, b = 1;

        for(int i = 2; i <= n; i++){
            bool b1 = (s[i-1] != '0');
            int doub = (s[i-2] - '0')*10 + (s[i-1] - '0');
            bool b2 = (doub >= 10 and doub <= 26);
            int c = 0;

            if(b1 and b2) c = a + b;
            else if(b1 and !b2) c = b;
            else if(!b1 and b2) c = a;
            else c = 0;

            a = b;
            b = c;
        }

        return b;
    }
};
