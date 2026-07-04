class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int l = 0, r = (int)points.size()-1;
        int pivot = r+1;

        while(pivot != k){
            pivot = partition(points, l, r);
            if(pivot > k) r = pivot-1;
            else l = pivot+1;
        }

        return vector<vector<int>> (points.begin(), points.begin() + k);
    }

    int partition(vector<vector<int>>& points, int l, int r){
        int pivot_idx = r;
        int pivot_dist = euc(points[pivot_idx]);

        int i = l;

        for(int j = l; j < r; j++){
            if(euc(points[j]) <= pivot_dist){
                swap(points[j], points[i]);
                i++;
            }
        }

        swap(points[r], points[i]);

        return i;
   }

   int euc(vector<int>& point){
        return (point[0]*point[0] + point[1]*point[1]);
   }
};
