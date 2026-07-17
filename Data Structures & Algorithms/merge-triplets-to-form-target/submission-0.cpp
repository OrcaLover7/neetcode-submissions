class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> good;

        for(auto& triplet : triplets){
            bool skip = false;
            for(int i = 0; i < 3; i++){
                if (triplet[i] > target[i]){
                    skip = true;
                    break;
                }
            }

            if(skip) continue;

            for(int i = 0; i < 3; i++) if(triplet[i] == target[i]) good.insert(i); 
        }

        return good.count(1) and good.count(2) and good.count(0);
    }

};
