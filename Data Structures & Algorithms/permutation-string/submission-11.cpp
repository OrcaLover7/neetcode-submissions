class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = (int)s1.size(), n2 = (int)s2.size();

        if(n1 > n2) return false;

        array<int, 26> f1 = {0};
        array<int, 26> window_f = {0};

        for(char c : s1) f1[c-'a']++;

        int l = 0, r = 0;

        while(r < n2){
            window_f[s2[r] - 'a']++;
            int len = r-l+1;

            if(len == n1){
                if(window_f == f1) return true;
                else{
                    window_f[s2[l] - 'a']--;
                    l++;
                }
            }

            r++;
        }

        return false;
    }
};
