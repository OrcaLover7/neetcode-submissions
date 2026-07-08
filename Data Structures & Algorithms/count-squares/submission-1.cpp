class CountSquares {
public:
    map<pair<int, int>, int> freq;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        freq[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1];
        int ans = 0;

        for(auto& [p, cnt] : freq){
            auto [x2, y2] = p;

            if(x1 == x2 or y1 == y2) continue;

            int x3 = x1, y3 = y2, x4 = x2, y4 = y1;

            if(freq.count({x3, y3}) and freq.count({x4, y4})) ans += cnt*freq[{x3, y3}]*freq[{x4, y4}];
        }

        return ans;
    }
};
