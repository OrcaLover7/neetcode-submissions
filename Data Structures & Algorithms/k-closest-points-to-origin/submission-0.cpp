class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        auto cmp = [](const vector<int>& a, const vector<int>& b){
            return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> maxHeap(cmp);

        for(auto& point : points){
            if(maxHeap.size() == k){
                if(cmp(point, maxHeap.top())){
                    maxHeap.pop();
                    maxHeap.push(point);
                }
            }
            else    maxHeap.push(point);
        }

        vector<vector<int>> ans;

        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top());
            maxHeap.pop();
        }

        return ans;
    }
};
