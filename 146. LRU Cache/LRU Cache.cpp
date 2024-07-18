class LRUCache {
private:
    int capacity;
    list<pair<int, int>> l; // Doubly linked list of (key, value) pairs
    unordered_map<int, list<pair<int, int>>::iterator> m; // Map from key to iterator of list node

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) return -1;
        l.splice(l.begin(), l, it->second); // Move the accessed node to the front
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) {
            l.erase(it->second); // If key already exists, remove the old node
        }
        l.push_front({key, value}); // Add a new node to the front
        m[key] = l.begin();
        if (m.size() > capacity) { // If over capacity, remove the least recently used node
            int k = l.rbegin()->first;
            l.pop_back();
            m.erase(k);
        }
    }
};