class Solution {
public:
    int getSum(int a, int b) {
        unsigned x = a, y = b;

        while(y){
            unsigned sum = x ^ y;
            unsigned carry = (x & y) << 1;

            x = sum;
            y = carry;
        }

        return x;
    }
};
