// clang++ repeatedDNASequences.cpp -std=c++11

#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution{
public:
  vector<vector<string> > findDuplicate(vector<string>& paths) {
    unordered_map<string, vector<string> > fileMap;
    vector<vector<string> > ans;
    for (string& path : paths) {
      istringstream iss(path);
      string dir;
      getline(iss, dir, ' ');
      string file;
      while (getline(iss, file, ' ')) {
	string fileName = dir + "/" + file.substr(0, file.find('('));
	string fileContent = file.substr(file.find('(') + 1, file.find(')') - file.find('(')- 1);
	fileMap[fileContent].push_back(fileName);
      }
    }
    for (auto file : fileMap) {
      if (file.second.size() > 1)
	ans.push_back(file.second);
    }
    return ans;
  }
};

int main()
{
  Solution s;
  string s1 = "root/a 1.txt(abcd) 2.txt(efgh),root/c 3.txt(abcd),root/c/d 4.txt(efgh),root 4.txt(efgh)";
  istringstream iss(s1);
  string word;
  vector<string> paths;
  while (getline(iss, word, ',')) {
    paths.push_back(word);
  }
  vector<vector<string> > res = s.findDuplicate(paths);
  for (vector<string> &vec : res) {
    for (string &ss : vec)
      cout << ss << " ";
    cout << endl;
  }
  return 0;
}
