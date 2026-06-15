class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> time_map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) { 
        time_map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = time_map.find(key);
        if(it == time_map.end()) return "";

        auto& arr = it->second;

        auto it1 = upper_bound(arr.begin(), arr.end(), timestamp, [] (int ts, const pair<int, string>& p1){ return p1.first > ts; });

        if(it1 == arr.begin()) return "";
        return std::prev(it1)->second;
    }
};
