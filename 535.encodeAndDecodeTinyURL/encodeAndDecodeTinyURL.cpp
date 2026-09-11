#include <iostream>
#include <cmath>
#include <unordered_map>
#include <ctime>
#include <cstdlib>
using namespace std;

class Solution{
public:
  string encode(string longUrl) {
    unordered_map<string, string>::iterator it = long2shortMap.begin();
    if (it != long2shortMap.end()) {
      return BASE_HOST + it->second;
    }
    string shortUrl = "";
    do {
      shortUrl = randomGenerate();
      it = short2longMap.find(shortUrl);
    } while (it != short2longMap.end());
    long2shortMap.insert(make_pair(longUrl, shortUrl));
    short2longMap.insert(make_pair(shortUrl, longUrl));
    return BASE_HOST + shortUrl;
  }
  string decode(string shortUrl) {
    string longUrl = "";
    size_t pos = shortUrl.find(BASE_HOST);
    if (pos != string::npos)
      pos += BASE_HOST.length();
    unordered_map<string, string>::iterator it = short2longMap.find(shortUrl.substr(pos));
    if (it != short2longMap.end()) {
       longUrl =  it->second;
    }
    return longUrl;
  }
  string randomGenerate() {
    string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string key = "";
    int len = charset.length();
    srand(time(NULL));
    for (int i = 0; i < 6; i++) {
      int randomIndex = rand() % len;
      key += charset[randomIndex];
    }
    return key;
  }
private:
  string BASE_HOST = "http://tinyurl.com/";
  unordered_map<string, string> long2shortMap;
  unordered_map<string, string> short2longMap;
};

int main()
{
  Solution s;
  string url = "https://leetcode.com/problems/design-tinyurl";
  string tinyUrl = s.encode(url);
  cout << tinyUrl << endl;
  cout << s.decode(tinyUrl) << endl;
  return 0;
}
