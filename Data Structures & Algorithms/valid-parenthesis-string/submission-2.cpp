class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0, hi = 0;

        for(char c : s){
            if(c == '('){
                lo++;
                hi++;
            }
            else if(c == ')'){
                lo--;
                hi--;
            }
            else{
                lo--;
                hi++;
            }

            if(hi < 0) return false;

            lo = max(0, lo);
        }

        return lo == 0;
    }
};
