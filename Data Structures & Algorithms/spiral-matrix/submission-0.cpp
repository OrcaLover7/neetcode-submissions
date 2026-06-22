class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        int t = 0, b = m-1, l = 0, r = n-1;

        vector<int> ans;

        while(t <= b and l <= r){
            for(int j = l; j <= r; j++) ans.push_back(matrix[t][j]);
            for(int i = t+1; i <= b; i++) ans.push_back(matrix[i][r]);
            if(t != b) for(int j = r-1; j >= l; j--) ans.push_back(matrix[b][j]);
            if(l != r) for(int i = b-1; i > t; i--) ans.push_back(matrix[i][l]);

            t++; b--; l++; r--;
        }
        
        return ans;

    }
};
