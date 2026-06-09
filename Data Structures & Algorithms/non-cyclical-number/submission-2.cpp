class Solution {
public:
    bool isHappy(int n) {
        int slow = square_helper(n);
        int fast = square_helper(square_helper(n));

        if(fast == 1) return true;

        while(slow != fast){
            if(fast == 1) return true;
            slow = square_helper(slow);
            fast = square_helper(square_helper(fast));
        }

        return false;
    }

    int square_helper(int n){
        int sum = 0;

        while(n){
            int digit = n%10;
            n/=10;
            sum += digit*digit;
        }

        return sum;
    }
};
