class Solution {
public:
    int trap(vector<int>& height) {
        int n = (int)height.size();

        int ml = height[0];
        int mr = height[n-1];

        int l = 0, r = n-1;
        int area = 0;

        while(l < r){
            if(ml < mr){
                l++;
                ml = max(ml, height[l]);
                area += ml-height[l];
            }
            else{
                r--;
                mr = max(mr, height[r]);
                area += mr - height[r];
            }
        }

        return area;
    }
};
