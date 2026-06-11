class Solution {
public:
    bool isHappy(int n) {
        int slow = helper(n);
        int fast = helper(helper(n));

        if(slow == fast) return true;

        while(slow != fast){
            if(fast == 1) return true;
            slow = helper(slow);
            fast = helper(helper(fast));
        }

        return false;
    }

    int helper(int n){
        int result = 0;

        while(n){
            int digit = n%10;
            n /= 10;

            result += digit*digit;
        }

        return result;
    }
};
