class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();

        for(int i = 0; i < n/2; i++){
            for(int j = i; j < n-1-i; j++){
                int a = matrix[i][j];
                int b = matrix[j][n-1-i];
                int c = matrix[n-1-i][n-1-j];
                int d = matrix[n-1-j][i];

                int tmp = a;
                matrix[i][j] = d;
                matrix[n-1-j][i] = c;
                matrix[n-1-i][n-1-j] = b;
                matrix[j][n-1-i] = tmp;
            }
        }
    }
};
