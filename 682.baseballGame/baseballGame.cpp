#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int calPoints(vector<string>& ops) {
    int res = 0;
    vector<int> round;
    for (const string& op : ops) {
      int point = 0;
      if (op == "C") {
	res -= round.back();
	round.pop_back();
      } else if (op == "D") {
        point = round.back() * 2;
	round.push_back(point);
	res += point;
      } else if (op == "+") {
	point = round.back() + round[round.size() - 2];
	round.push_back(point);
	res += point;
      } else {
        point = stoi(op);
	round.push_back(point);
	res += point;
      }
    }
    return res;
  }
};

int main()
{
  Solution s;
  vector<string> ops = {"5", "2", "C", "D", "+"};
  cout << s.calPoints(ops);
  cout << endl;
  vector<string> ops2 = {"5", "-2", "4", "C", "D", "9", "+", "+"};
  cout << s.calPoints(ops2);
  cout << endl;
  return 0;
}
