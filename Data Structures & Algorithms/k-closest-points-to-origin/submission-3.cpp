class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int l = 0, r = points.size()-1;
        int pivot = points.size();

        while(pivot != k){
            pivot = partition(points, l, r);

            if(pivot < k){
                l = pivot+1;
            }
            else{
                r = pivot-1;
            }
        }

        return vector<vector<int>> (points.begin(), points.begin() + k);
    }

    int partition(vector<vector<int>>& a, int l, int r){
        int pivotidx = r;
        int pivotdist = euclidean(a[pivotidx]);
        
        int i = l;
        for(int j = l; j < r; j++){
            if(euclidean(a[j]) <= pivotdist){
                swap(a[j], a[i]);
                i++;
            }
        }

        swap(a[i], a[r]);

        return i;
    }
        int euclidean(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
};
