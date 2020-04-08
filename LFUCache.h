//
// Created by August on 4/5/20.
//

/**
 * 460. LFU缓存
 * https://leetcode-cn.com/problems/lfu-cache/
 */

#ifndef LEETCODE_LFUCACHE_H
#define LEETCODE_LFUCACHE_H

#include <list>
#include <unordered_map>

using namespace std;

class LFUCache {
public:
    LFUCache(int capacity) {
        max_cap = capacity;
        table.clear();
        l.clear();
    }

    ~LFUCache() {
        table.clear();
        l.clear();
    }

    int get(int key) {
        auto it = table.find(key);
        if (it == table.end()) return -1;
        auto it2 = find(l.begin(), l.end(), key);
        auto next = it2++;
        if (next != l.end()) {

//            l.insert(next, key);
            l.erase(it2);

        }
        return it->second;
    }

    void put(int key, int value) {
        if (table.find(key) != table.end()) {
            table[key] = value;
            get(key);
        } else {
            if (table.size() >= max_cap) {
                int min = *l.begin();
                table.erase(min);
                l.pop_front();
            }
            l.push_front(key);
            table[key] = value;
        }
    }

private:
    int max_cap;
    unordered_map<int, int> table;
    list<int> l;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#endif //LEETCODE_LFUCACHE_H
