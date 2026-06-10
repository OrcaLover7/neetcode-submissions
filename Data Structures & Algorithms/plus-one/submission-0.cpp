class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;

        int carry = 1;
        int n = (int)digits.size();

        for(int i = n-1; i >= 0; i--){
            int sum = digits[i] + carry;
            carry = sum/10;
            ans.push_back(sum%10);
        }

        if(carry) ans.push_back(1);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
