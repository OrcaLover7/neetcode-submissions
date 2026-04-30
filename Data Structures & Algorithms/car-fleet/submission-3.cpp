class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<double, int>> cars; //time, position
        int n = position.size();
        cars.reserve(n);

        for(int i = 0; i < n; i++){
            double t = ((target - position[i])*1.0)/speed[i];
            cars.push_back({t, position[i]});
        }

        sort(cars.begin(), cars.end(), [](auto& a, auto& b) {return a.second > b.second;});

        double ceiling = 0.0;
        int fleets = 0;

        for(auto& [t, _] : cars){
            if(t > ceiling){
                fleets++;
                ceiling = t;
            }
        }
        return fleets;
    }
};
