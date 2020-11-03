class LRUCache {
  private:
    std::list<std::pair<int, int>> dl{};
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m{};
    int _capacity;

  public:
    LRUCache(int capacity) : _capacity(capacity) { m.reserve(_capacity); }

    int get(int key) {
        auto it = m.find(key);
        if (it != m.end()) {
            dl.splice(dl.begin(), dl, it->second);
            return it->second->second;
        }
        return -1;
    }

    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) {
            dl.splice(dl.begin(), dl, it->second);
            it->second->second = value;
            return;
        }
        dl.emplace_front(key, value);
        m[key] = dl.begin();
        if (m.size() > _capacity) {
            m.erase(dl.back().first);
            dl.pop_back();
        }
    }
};