// clang++ LRUCache2.cpp -std=c++11

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class DLinkedNode {
public:
  DLinkedNode() : key(0), value(0), prev(NULL),next(NULL) {
  }
  DLinkedNode(int k, int v) : key(k), value(v), prev(NULL), next(NULL) {
  }
  int key;
  int value;
  DLinkedNode *prev;
  DLinkedNode *next;
};

class LRUCache {
public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    size = 0;
    cacheListHead = new DLinkedNode;
    cacheListTail = new DLinkedNode;
    cacheListHead->next = cacheListTail;
    cacheListTail->prev = cacheListHead;
  }
  int get(int key) {
    unordered_map<int, DLinkedNode*>::iterator it = cacheMap.find(key);
    if (it == cacheMap.end()) { // if not exist in cache
      return -1;
    } else {
      // move it to the list head
      moveNodeToHead(it->second);
      return it->second->value;
    }
  }
  void put(int key, int value) {
    unordered_map<int, DLinkedNode*>::iterator it = cacheMap.find(key);
    if (it == cacheMap.end()) { // if not exist in cache
      if (size == capacity) { // if cache is full
        DLinkedNode* n = removeTail();
	if (n) {
	  cacheMap.erase(n->key);
	  delete n;
	}
	size--;
      }
      DLinkedNode *temp = new DLinkedNode(key, value);
      addNode(temp);
      cacheMap.insert(make_pair(key, temp));
      size++;
    } else { // if already eixst in cache
      // move it to the list head
      it->second->value = value;
      moveNodeToHead(it->second);
    }
  }
  ~LRUCache() {
     unordered_map<int, DLinkedNode*>::iterator it = cacheMap.begin();
     while (it != cacheMap.end()) {
       delete it->second;
       ++it;
     }
     cacheMap.clear();
     delete cacheListHead;
     delete cacheListTail;
  }
private:
  unordered_map<int, DLinkedNode*> cacheMap;
  DLinkedNode* cacheListHead, *cacheListTail;
  int capacity;
  int size;
  void addNode(DLinkedNode* n) {
    n->prev = cacheListHead;
    n->next = cacheListHead->next;
    cacheListHead->next->prev = n;
    cacheListHead->next = n;
  }
  void removeNode(DLinkedNode* n) {
    n->prev->next = n->next;
    n->next->prev = n->prev;
  }
  void moveNodeToHead(DLinkedNode* n) {
    n->prev->next = n->next;
    n->next->prev = n->prev;
    addNode(n);
  }
  DLinkedNode* removeTail() {
    DLinkedNode* n = NULL;
    if (cacheListTail->prev != cacheListHead) {
      n = cacheListTail->prev;
      removeNode(n);
    }
    return n;
  }
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
