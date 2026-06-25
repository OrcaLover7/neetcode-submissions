class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();

        int top = 0, bottom = m-1, left = 0, right = n-1;
        vector<int> ans;

        while(top <= bottom && left <= right){
            // Top row: left to right (inclusive)
            for(int j = left; j <= right; j++) ans.push_back(matrix[top][j]);
            top++;

            // Right column: top to bottom (exclusive of top corner already added)
            for(int i = top; i <= bottom; i++) ans.push_back(matrix[i][right]);
            right--;

            if(top > bottom || left > right) break;

            // Bottom row: right to left (inclusive, exclusive of right corner)
            for(int j = right; j >= left; j--) ans.push_back(matrix[bottom][j]);
            bottom--;

            // Left column: bottom to top (exclusive of bottom and top corners)
            for(int i = bottom; i >= top; i--) ans.push_back(matrix[i][left]);
            left++;
        }

        return ans;
    }
};