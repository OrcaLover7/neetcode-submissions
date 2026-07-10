class CountSquares {
public:
    map<pair<int, int>, int> point_freq;

    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        point_freq[{point[0], point[1]}]++;    
    }
    
    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1];

        int ans = 0;

        for(auto& [p, cnt] : point_freq){
            auto [x2, y2] = p;

            if(x1 == x2 or y1 == y2) continue;

            int x3 = x1, y3 = y2, x4 = x2, y4 = y1;

            if(point_freq.count({x3, y3}) and point_freq.count({x4, y4})) ans += cnt*point_freq[{x3, y3}]*point_freq[{x4, y4}];
        }

        return ans;
    }
};
