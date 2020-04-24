/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

*/

//Solution

class LRUCache {
    unordered_map<int,list<pair<int,int>>::iterator> cache;
    list<pair<int,int>> lru;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto found = cache.find(key);
        if(found == cache.end())
            return -1;
        lru.splice(lru.begin(),lru,found->second);
        return found->second->second;    
    }
    
    void put(int key, int value) {
        auto found = cache.find(key);
        if(found != cache.end()) {
            lru.splice(lru.begin(),lru,found->second);
            found->second->second = value;
            return;                       
        }
        if(cache.size() == cap) {
            int del_key = lru.back().first;
            lru.pop_back();
            cache.erase(del_key);
        }
        lru.emplace_front(key,value);
        cache[key] = lru.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
