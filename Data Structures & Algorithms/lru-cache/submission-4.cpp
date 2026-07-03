class LRUCache {
    int _cap;
    list<pair<int, int>> _ls;
    unordered_map<int, std::list<pair<int, int>>::iterator> _cache;
public:

    LRUCache(int capacity) {
        _cap = capacity;
    }
    
    int get(int key) {
        auto it = _cache.find(key);
        if(it == _cache.end()) return -1;

        _ls.splice(_ls.end(), _ls, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = _cache.find(key);

        if(it == _cache.end()){
            if(_cap == (int)_cache.size()){
                int prev_key = _ls.begin()->first;
                _ls.erase(_ls.begin());
                _cache.erase(prev_key);
            }

            _ls.emplace_back(key, value);
            _cache[key] = std::prev(_ls.end());
        }
        else{
            it->second->second = value;
            _ls.splice(_ls.end(), _ls, it->second);
        }
    }
};
