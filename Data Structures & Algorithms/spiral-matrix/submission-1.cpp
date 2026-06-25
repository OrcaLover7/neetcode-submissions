class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();

        int top = 0, bottom = m, right = n, left = 0;
        vector<int> ans;

        while(top < bottom and left < right){
            for(int j = left; j < right; j++) ans.push_back(matrix[top][j]);
            top++;

            for(int i = top; i < bottom; i++) ans.push_back(matrix[i][right-1]);
            right--;

            if(!(left < right && top < bottom)) break;
            
            for(int j = right-1; j >= left; j--) ans.push_back(matrix[bottom-1][j]);
            bottom--;

            for(int i = bottom-1; i >= top; i--) ans.push_back(matrix[i][left]);
            left++;
        }

        return ans;
    }
};
