class LRUCache{
    int _capacity;
    std::list<pair<int, int>> cache;
    unordered_map<int, std::list<pair<int, int>>::iterator> mp;
public:
    LRUCache(int capacity): _capacity(capacity) {}

    int get(int key){
        auto it = mp.find(key);

        if(it != mp.end()){
            cache.splice(cache.end(), cache, it->second);
            return (it->second)->second;
        }
        else return -1;
    }

    void put(int key, int value){

        auto it = mp.find(key);

        if(it != mp.end()){
            (it->second)->second = value;
            cache.splice(cache.end(), cache, it->second);
        }
        else{
            if(_capacity == cache.size()){
                int prev_tail_key = cache.begin()->first;// or int prev_tail_key = cache.front().first;
                cache.erase(cache.begin());
                mp.erase(prev_tail_key);
            }
                cache.emplace_back(key, value);
                mp[key] = std::prev(cache.end());
        }
    }


};