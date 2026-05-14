class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();

        int l = 0, h = m*n - 1;

        while(l <= h){
            int mid = l + (h-l)/2;
            
            int curr = matrix[mid/n][mid%n];

            if(curr == target) return true;

            if(curr > target) h = mid-1;
            else l = mid+1;
        }

        return false;
    }
};
