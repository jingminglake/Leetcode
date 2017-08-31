// clang++ designTwitter.cpp -std=c++11

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Tweet {
public:
  static int timeStamp;
  Tweet(int id) : tweetId(id), tweetTime(timeStamp++),next(NULL){}
  int getTweetTime() const { return tweetTime; }
  int getTweetId() const {return tweetId;}
  Tweet *getNext() {return next;}
  void setNext(Tweet *n) { next = n;}
private:
  int tweetId;
  int tweetTime;
  Tweet *next;
};
int Tweet::timeStamp = 0;

class User {
public:
  User(int id) : userId(id) {
    tweetList = nullptr;
  }
  void follow(int id) {
    followed.insert(id);
  }
  void unfollow(int id) {
    unordered_set<int>::iterator it = followed.find(id);
    if (it != followed.end())
      followed.erase(it);
  }
  void post(int id) {
    Tweet *t = new Tweet(id);
    t->setNext(tweetList);
    tweetList = t;
  }
  unordered_set<int>& getFollowed() {
    return followed;
  }
  Tweet* getTweetList() const { return tweetList;}
private:
  int userId;
  unordered_set<int> followed;
  Tweet *tweetList;
};

class Compare {
public:
  bool operator()(const Tweet* t1, const Tweet* t2) const {
    return t1->getTweetTime() <  t2->getTweetTime();
  }
};

class Twitter{
public:
  /** Initialize your data structure here. */
  Twitter() {
        
  }
    
  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    if (userMap.find(userId) == userMap.end()) {
      User *u = new User(userId);
      userMap.insert(make_pair(userId, u));
    }
    userMap[userId]->post(tweetId);
  }
    
  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    vector<int> newsFeed;
    if (userMap.find(userId) == userMap.end())
      return newsFeed;
    unordered_set<int>& followedUsers = userMap[userId]->getFollowed();
    priority_queue<Tweet*, vector<Tweet*>, Compare > pq;
    unordered_set<int>::iterator it = followedUsers.begin();
    while (it != followedUsers.end()) {
      Tweet *t = userMap[*it]->getTweetList();
      if (t)
	pq.push(t);
      ++it;
    }
    Tweet *myTweet = userMap[userId]->getTweetList();
    if (myTweet)
      pq.push(myTweet);
    int n = 0;
    while (!pq.empty() && n < 10) {
      Tweet *t = pq.top();
      pq.pop();
      newsFeed.push_back(t->getTweetId());
      n++;
      if (t->getNext())
	pq.push(t->getNext());
    }
    return newsFeed;
  }
    
  /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
  void follow(int followerId, int followeeId) {
    if (followerId == followeeId)
      return;
    if (userMap.find(followerId) == userMap.end()) {
      User *u = new User(followerId);
      userMap.insert(make_pair(followerId, u));
    }
    if (userMap.find(followeeId) == userMap.end()) {
      User *u = new User(followeeId);
      userMap.insert(make_pair(followeeId, u));
    }
    userMap[followerId]->follow(followeeId);
  }
    
  /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
  void unfollow(int followerId, int followeeId) {
    if (followerId == followeeId || userMap.find(followerId) == userMap.end() || userMap.find(followeeId) == userMap.end()) {
      return;
    }
    userMap[followerId]->unfollow(followeeId);
  }
  ~Twitter() {
    unordered_map<int, User*>::iterator it = userMap.begin();
    while (it != userMap.end()) {
      delete it->second;
      ++it;
    }
    userMap.clear();
  }
private:
  unordered_map<int, User*> userMap;
};

int main()
{
  Twitter obj;
  obj.postTweet(1,5);
  vector<int> param_2 = obj.getNewsFeed(1);
  for (int i : param_2) {
    cout << i << " ";
  }
  cout << endl;
  obj.follow(1, 2);
  obj.postTweet(2, 6);
  vector<int> param_3 = obj.getNewsFeed(1);
  for (int i : param_3) {
    cout << i << " ";
  }
  cout << endl;
  obj.unfollow(1,2);
  vector<int> param_4 = obj.getNewsFeed(1);
  for (int i : param_4) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
