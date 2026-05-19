class Solution {
public:
    //nubmer of ways of reaching step i = number fo ways of reaching step i-1 + step i-2
    //number of ways of reaching step 0 = 1, number of ways of reach ing step 1 = 1
    int climbStairs(int n) {
        vector<int> memo(n+1, -1);
        return helper(n, memo);
    }

    int helper(int n, vector<int>& memo){
        if(n <= 1) return 1;

        if(memo[n] != -1) return memo[n];

        return memo[n] = helper(n-1, memo) + helper(n-2, memo);
    }
};
