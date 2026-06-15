class TimeMap {
public:
    unordered_map<string, map<int, string>> time_map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) { 
        time_map[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = time_map.find(key);
        if(it == time_map.end()) return "";

        auto& mp = it->second;

        auto it1 = mp.upper_bound(timestamp);

        if(it1 == mp.begin()) return "";
        return std::prev(it1)->second;
    }
};
