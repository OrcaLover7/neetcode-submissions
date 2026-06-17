class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> tbkv;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        tbkv[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it1 = tbkv.find(key);

        if(it1 == tbkv.end()) return "";
        
        auto it2 = upper_bound(it1->second.begin(), it1->second.end(), timestamp, [](const int& time, const pair<int, string>& p) { return p.first > time; });

        if(it2 == it1->second.begin()) return "";

        return std::prev(it2)->second;
    }
};
