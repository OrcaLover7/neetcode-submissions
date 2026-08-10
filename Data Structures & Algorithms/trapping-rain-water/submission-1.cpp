class Solution {
public:
    int trap(vector<int>& height) {
        int n = (int)height.size();
        int area = 0;

        vector<int> prefix(n, -1), suffix(n, -1);
        prefix[0] = height[0], suffix[n-1] = height[n-1];

        for(int i = 1; i < n; i++) prefix[i] = max(prefix[i-1], height[i]);
        for(int i = n-2; i >= 0; i--) suffix[i] = max(suffix[i+1], height[i]);

        for(int i = 0; i < n; i++) area += min(prefix[i], suffix[i]) - height[i];
        return area;
    }
};
