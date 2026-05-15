class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int l = 0, r = (int)heights.size()-1;

        int ans = 0;
        while(l < r){
            int curr_area = min(heights[l], heights[r])*(r-l);
            ans = max(ans, curr_area);

            if(heights[l] < heights[r]) l++;
            else r--;
        }

        return ans;
    }
};
