class LRUCache {
    int _cap;
    std::list<pair<int, int>> _cache;
    unordered_map<int, std::list<pair<int, int>>::iterator> _mp;
public:
    LRUCache(int capacity): _cap(capacity) {}
    
    int get(int key) {
        auto it = _mp.find(key);

        if(it != _mp.end()){
            _cache.splice(_cache.end(), _cache, it->second);
            return it->second->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = _mp.find(key);

        if(it != _mp.end()){
            it->second->second = value;
            _cache.splice(_cache.end(), _cache, it->second);
        }
        else{
            if(_cache.size() == _cap){
                int prev_tail_key = _cache.begin()->first;
                _mp.erase(prev_tail_key);
                _cache.erase(_cache.begin());

            }

            _cache.emplace_back(key, value);
            _mp[key] = std::prev(_cache.end());
        }
    }
};
