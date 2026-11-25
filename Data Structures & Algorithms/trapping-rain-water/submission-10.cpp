class Solution {
public:
    int trap(vector<int>& height) {
        int n = (int)height.size();
        vector<int> lm(n, 0), rm(n, 0);

        for(int i = 1; i < n; i++) lm[i] = max(lm[i-1], height[i-1]);
        for(int i = n-2; i >= 0; i--) rm[i] = max(rm[i+1], height[i+1]);

        int area = 0;

        for(int i = 0; i < n; i++){
            area += max(0, min(lm[i], rm[i]) - height[i]);
        }

        return area;
    }
};
