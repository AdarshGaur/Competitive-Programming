// Author : @AdarshGaur

class LRUCache {
private:
    queue<int> q;
    list<int> List;
    unordered_map<int,int> cache;
    unordered_map<int, list<int>::iterator> recent;
    int _capacity = 0;
    
    void use(int key){
        if(cache.find(key) != cache.end()){
            List.erase(recent[key]);
        }else if(List.size() == _capacity){
            int old = List.back();
            cache.erase(old);
            recent.erase(old);
            List.pop_back();
        }
        List.push_front(key);
        recent[key] = List.begin();
    }

public:
    LRUCache(int capacity) : _capacity(capacity){}
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            use(key);
            return cache[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        use(key);
        cache[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
