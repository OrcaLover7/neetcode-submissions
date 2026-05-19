class Solution {
public:
    //nubmer of ways of reaching step i = number fo ways of reaching step i-1 + step i-2
    //number of ways of reaching step 0 = 1, number of ways of reach ing step 1 = 1
    int climbStairs(int n) {
        int a = 1, b = 1;

        for(int i = 2; i <= n; i++){
            int c = a + b;
            a = b;
            b = c;
        }

        return b;
    }
};
