// clang++ LRUCache.cpp -std=c++11

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <unordered_map>
using namespace std;

class Node {
public:
  Node() : key(0), value(0) {
  }
  Node(int k, int v) : key(k), value(v) {
  }
  int key;
  int value;
};

class LRUCache {
public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    cacheMap = unordered_map<int, list<Node*>::iterator>();
    cacheList = list<Node*>();
  }
  int get(int key) {
    unordered_map<int, list<Node*>::iterator >::iterator it = cacheMap.find(key);
    if (it == cacheMap.end()) { // if not exist in cache
      return -1;
    } else {
      // move it to the list head
      list<Node*>::iterator node = it->second;
      Node *newNode = new Node((*node)->key, (*node)->value);
      delete *node;
      cacheList.erase(node); // because list is modified, so node is invalid, could not use in the future
      cacheList.push_front(newNode);
      it->second = cacheList.begin(); // renew a iterator
      return newNode->value;
    }
  }
  void put(int key, int value) {
    unordered_map<int, list<Node*>::iterator >::iterator it = cacheMap.find(key);
    if (it == cacheMap.end()) { // if not exist in cache
      if (cacheList.size() == capacity) { // if cache is full
	Node *n = cacheList.back();
	cacheMap.erase(n->key);
	delete n;
	cacheList.pop_back();
      }
      Node *temp = new Node(key, value);
      cacheList.push_front(temp);
      cacheMap.insert(make_pair(key, cacheList.begin()));
    } else { // if already eixst in cache
      // move it to the list head
      list<Node*>::iterator node = it->second;
      Node *newNode = new Node((*node)->key, value);
      delete *node;
      cacheList.erase(node);
      cacheList.push_front(newNode);
      it->second = cacheList.begin();
    }
  }
  ~LRUCache() {
     list<Node*>::iterator it = cacheList.begin();
     while (it != cacheList.end()) {
       delete *it;
       ++it;
     }
     cacheList.clear();
     cacheMap.clear();
  }
private:
  unordered_map<int, list<Node*>::iterator > cacheMap;
  list<Node*> cacheList;
  int capacity;
};

int main()
{
  LRUCache cache(2);
  cout << cache.get(2) << endl;
  cache.put(2, 6);
  cout << cache.get(1) << endl;
  cache.put(1, 5);
  cache.put(1, 2);
  cout << cache.get(1) << endl;
  cout << cache.get(2) << endl;
  return 0;
}
