class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;

        for(int i = 0; i < 32; i++){
            ans = ans + ((n & (1u << i)) ? 1 : 0);
        }

        return ans;
    }
};
