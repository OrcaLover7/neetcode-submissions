class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> tbkv;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        tbkv[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = tbkv.find(key);

        if(it != tbkv.end()){
            auto iter = upper_bound(it->second.begin(), it->second.end(), timestamp, [] (const int& ts, pair<int, string>& p) { return p.first > ts; });
            if(iter == it->second.begin()) return "";
            return (--iter)->second;
        }

        return "";
    }
};
