class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" or num2 == "0") return "0";
        int m = (int)num1.size();
        int n = (int)num2.size();

        vector<int> res(m+n, 0);

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for(int i1 = 0; i1 < m; i1++){
            for(int i2 = 0; i2 < n; i2++){
                int digit = (num1[i1] - '0')*(num2[i2] - '0');
                res[i1+i2] += digit;
                res[i1+i2+1] += res[i1+i2]/10;
                res[i1+i2] %= 10;
            }
        }

        int i1 = m + n - 1;
        string result = "";

        while(i1 >= 0 and res[i1] == 0) i1--;

        while(i1 >= 0) result.push_back(res[i1--] + '0');

        return result;  
    }
};
