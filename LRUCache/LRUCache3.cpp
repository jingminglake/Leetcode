// clang++ LRUCache2.cpp -std=c++11

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class DNode {
public:
    DNode() : prev(nullptr), next(nullptr), key(0), val(0) {}
    DNode(int _key, int _val) : prev(nullptr), next(nullptr), key(_key), val(_val) {}
    DNode *prev;
    DNode *next;
    int key;
    int val;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
        size = 0;
        dummy1.next = &dummy2;
        dummy2.prev = &dummy1;
    }
    ~LRUCache() {
        unordered_map<int, DNode*>::iterator it = m.begin();
        while (it != m.end()) {
            delete it->second;
            ++it;
        }
        m.clear();
    }
    void moveToHead(DNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        dummy1.next->prev = node;
        node->next = dummy1.next;
        node->prev = &dummy1;
        dummy1.next = node;
    }
    
    void removeNode(DNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
    
    void addToHead(DNode* node) {
        dummy1.next->prev = node;
        node->next = dummy1.next;
        node->prev = &dummy1;
        dummy1.next = node;
    }
    
    void removeTail() {
        //cout << "erase: " << dummy2.prev->key << endl;
        m.erase(dummy2.prev->key);
        removeNode(dummy2.prev);
    }
    
    int get(int key) {
        if (m.count(key)) {
            moveToHead(m[key]);
            return m[key]->val;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (m.count(key)) {
            m[key]->val = value;
            moveToHead(m[key]);
        } else {
            if (size < _capacity) {
                size++;
                DNode *node = new DNode(key, value);
                m[key] = node;
                addToHead(node);
            } else if (size == _capacity) {
                removeTail();
                DNode *node = new DNode(key, value);
                m[key] = node;
                addToHead(node);
            }
        }
    }
    int _capacity;
    int size;
    DNode dummy1;
    DNode dummy2;
    unordered_map<int, DNode*> m;
};


int main()
{
  LRUCache cache(2);
  cache.put(1, 1);
  cache.put(2, 2);
  cout << cache.get(1) << endl;
  cache.put(3, 3);
  cout << cache.get(2) << endl;
  cache.put(4, 4);
  cout << cache.get(1) << endl;
  cout << cache.get(3) << endl;
  cout << cache.get(4) << endl;
  return 0;
}
