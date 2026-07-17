class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool x = false, y = false, z = false;

        for(auto& t : triplets){
            if(t[0] == target[0] and t[1] <= target[1] and t[2] <= target[2]) x = true;
            if(t[0] <= target[0] and t[1] == target[1] and t[2] <= target[2]) y = true;
            if(t[0] <= target[0] and t[1] <= target[1] and t[2] == target[2]) z = true;

            if(x and y and z) return true;
        }

        return x and y and z;
    }

};
