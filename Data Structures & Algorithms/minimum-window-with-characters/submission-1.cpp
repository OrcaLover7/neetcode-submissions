class Solution {
public:

    bool check(string& s, vector<int>& freq_t, int w, string& ans){
        vector<int> freq_ss(128, 0);
        int l = 0, r = 0;
        int n = (int)s.size();

        while(r < n){
            freq_ss[s[r]]++;
            int curr_w = r - l + 1;
            if(curr_w > w){
                freq_ss[s[l]]--;
                l++;
            }

            if(check2(freq_ss, freq_t)){
                ans = s.substr(l, w);
                return true;
            }
            r++;
        }

        return false;
    }

    bool check2(vector<int>& f1, vector<int>& f2){
        for(int i = 0; i < 128; i++) if (f1[i] < f2[i]) return false;
        return true;
    }
    string minWindow(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        if(n1 < n2) return "";

        int lo = n2, hi = n1+1;
        vector<int> freq_t(128, 0);
        for(char c : t) freq_t[c]++;

        string ans = "";

        while(lo < hi){
            int mid = lo + (hi-lo)/2;

            if(check(s, freq_t, mid, ans)) hi = mid;
            else lo = mid + 1;
        }

        return ans;
    }
};

