class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        return helper(n, st);
    }

    bool helper(int n, unordered_set<int>& st){
        int sum =0;

        while(n){
            int digit = n%10;
            n/=10;

            sum += digit*digit; //safe coz n <= 1000
        }

        if(st.count(sum)) return false;
        if(sum == 1) return true;

        st.insert(sum);

        return helper(sum, st);
    }
};
