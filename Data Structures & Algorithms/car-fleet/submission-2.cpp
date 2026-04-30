class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int, int>> cars;
        int n = position.size();

        for(int i = 0; i < n; i++){
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), greater<>());

        vector<double> times(n, 0);
        for(int i = 0; i < n; i++){
            times[i] = ((double)(target - cars[i].first))/cars[i].second;
        }

        double curr_time_ceiling = times[0];
        int fleet_count = 1;
        for(int i = 0; i < n; i++){
            double curr_time = times[i];
            if(curr_time_ceiling < curr_time){
                fleet_count++;
                curr_time_ceiling = curr_time;
            }
        }

        return fleet_count;
    }
};
