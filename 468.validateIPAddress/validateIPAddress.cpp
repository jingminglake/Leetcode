// clang++ validateIPAddress.cpp -std=c++11

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


class Solution{
public:
  string validIPAddress(string IP) {
    if (isValidIPv4(IP))
      return "IPv4";
    else if (isValidIPv6(IP))
      return "IPv6";
    else
      return "Neither";
  }
  bool isValidIPv4(string IP) {
    if (IP.back() == '.')
      return false;
    istringstream iss(IP);
    vector<string> vec;
    string ss;
    while (getline(iss, ss, '.') ) {
      if (ss.empty())
	return false;
      if (ss[0] == '0' && ss.length() > 1)
	return false;
      vec.push_back(ss);
    } 
    int size = vec.size();
    if (size != 4) {
      return false;
    }
    for (string& ss : vec) {
      int size = ss.length();
      int num = 0;
      for (int i = 0; i < size; i++) {
	if (ss[i] < '0' || ss[i] > '9')
	  return false;
	num *= 10;
	num += ss[i] - '0';
      }
      if (num < 0 || num > 255)
	return false;
    }
    return true;
  }
  bool isValidIPv6(string IP) {
    if (IP.back() == ':')
      return false;
    istringstream iss(IP);
    vector<string> vec;
    string ss;
    while (getline(iss, ss, ':') ) {
      vec.push_back(ss);
    } 
    int size = vec.size();
    if (size != 8) {
      return false;
    }
    for (string& ss : vec) {
      int len = ss.length();
      if (len < 1 || len > 4)
	return false;
      for (int i = 0; i < len; i++) {
	bool isDigit = ss[i] >= '0' && ss[i] <= '9';
	bool isUppercaseA2F = ss[i] >= 'a' && ss[i] <= 'f';
	bool isLowercaseA2F = ss[i] >= 'A' && ss[i] <= 'F';
	if (!(isDigit || isUppercaseA2F || isLowercaseA2F))
	  return false;
      }
    }
    return true;
  }
};

int main()
{
  Solution s;
  string ss = "172.16.154.025";
  string ss2 = "2001:0db8:85a3:0000:0000:8a2e:0370:7334";
  string ss3 = "2001:0db8:85a3:0:0:8a2e:0370:7334";
  string ss4 = "2001:0db8:85a3::8A2E:0370:7334";
  string ss5 = "02001:0db8:85a3:0000:0000:8a2e:0370:7334";
  cout << s.validIPAddress(ss) << endl;
  cout << s.validIPAddress(ss2) << endl;
  cout << s.validIPAddress(ss3) << endl;
  cout << s.validIPAddress(ss4) << endl;
  cout << s.validIPAddress(ss5) << endl;
  return 0;
}
