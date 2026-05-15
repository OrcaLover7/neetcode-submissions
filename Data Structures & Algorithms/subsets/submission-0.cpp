class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = (int)nums.size();
        vector<vector<int>> subsets;

        for(int i = 0; i < pow(2, n); i++){
            int k = i;
            vector<int> v;

            int j = 0;
            while(k){
                int a = k%2;
                k/=2;

                if(a) v.push_back(nums[j]);
                j++;
            }
            subsets.push_back(v);
        }

        return subsets;
    }
};
