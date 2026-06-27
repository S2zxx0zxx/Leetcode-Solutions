class LRUCache {
public:
    int cap;
    list<pair<int,int>> cache; // {key, val}
    unordered_map<int, list<pair<int,int>>::iterator> map;
    
    LRUCache(int capacity) : cap(capacity) {}
    
    int get(int key) {
        if (!map.count(key)) return -1;
        cache.splice(cache.begin(), cache, map[key]);
        return map[key]->second;
    }
    
    void put(int key, int value) {
        if (map.count(key)) {
            cache.splice(cache.begin(), cache, map[key]);
            map[key]->second = value;
        } else {
            if (cache.size() == cap) {
                map.erase(cache.back().first);
                cache.pop_back();
            }
            cache.push_front({key, value});
            map[key] = cache.begin();
        }
    }
};