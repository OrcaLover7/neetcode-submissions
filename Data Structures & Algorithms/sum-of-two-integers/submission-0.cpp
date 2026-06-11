class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0;
        int carry = 0;

        while(b){
            sum = a ^ b;
            carry = (a & b) << 1u;

            a = sum;
            b = carry;
        }

        return a;
    }
};
