class Solution {
public:
    int count_pal_centre(string& s, int l, int r){
        int count = 0;
        int n = (int)s.size();
        while(l >= 0 and r < n and s[l] == s[r]){
            count++;
            l--;
            r++;
        }

        return count;
    }

    int countSubstrings(string s) {
        int n = (int)s.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            //odd case
            ans += count_pal_centre(s, i, i);
            //even case
            ans += count_pal_centre(s, i, i+1);
        }

        return ans;
    }
};
