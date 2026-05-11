class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_set<char> window;
      int l = 0, ans = 0;

      for (int r = 0; r < (int)s.size(); r++) {
          while (window.count(s[r])) {       // invalid: duplicate present
              window.erase(s[l]);            // leave: s[l] removed
              l++;                           // l advances monotonically
          }
          window.insert(s[r]);               // enter: s[r] added
          ans = max(ans, r - l + 1);
      }
      return ans;
    }
};
