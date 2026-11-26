class Solution {
public:
    int trap(vector<int>& height) {
        int n = (int)height.size();
        if(n <= 2) return 0;

        int area = 0;
        int lmax = 0, rmax = 0;
        int l = 0, r = n-1;

        while(l < r){
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            if(lmax < rmax) area += (lmax - height[l++]);
            else area += (rmax - height[r--]);
        }

        return area;
    }
};