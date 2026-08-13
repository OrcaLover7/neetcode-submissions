class Solution {
public:
    int trap(vector<int>& height) {
        int n = (int)height.size();
        int ml = height[0], mr = height[n-1];
        int l = 0, r = n-1, area = 0;

        while(l < r){
            if(ml < mr){
                l++;
                ml = max(height[l], ml);
                area += ml-height[l];
            }
            else{
                r--;
                mr = max(height[r], mr);
                area += mr - height[r];
            }
        }

        return area;
    }
};
