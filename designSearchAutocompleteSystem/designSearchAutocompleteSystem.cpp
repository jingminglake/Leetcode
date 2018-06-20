#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
class AutocompleteSystem {
public:
    class TrieNode {
    public:
        TrieNode() : isWord(false) {
        }
        unordered_map<char, TrieNode*> kids;
        unordered_map<string, int> counts;
        bool isWord;
    };
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        root = new TrieNode();
        for (int i = 0; i < sentences.size(); i++) {
            addSentence (sentences[i], times[i]);
        }
    }
    void addSentence(string& sentence, int time) {
        TrieNode *cur = root;
        for (int i = 0; i < sentence.size(); i++) {
            if (!cur->kids[sentence[i]])
                cur->kids[sentence[i]] = new TrieNode();
            cur = cur->kids[sentence[i]];
            (cur->counts)[sentence] += time;
        }
        cur->isWord = true;
    }
    vector<string> input(char c) {
        vector<string> res;
        if (c == '#') {
            addSentence(prefix_sentence, 1);
            prefix_sentence = "";
            return res;
        }
        prefix_sentence += c;
        TrieNode *cur = root;
        for (char c : prefix_sentence) {
            cur = cur->kids[c];
            if (!cur)
                return res;
        }
        auto comp = [&](const pair<string, int>& p1, const pair<string, int>& p2) {
            return p1.second == p2.second ? p1.first > p2.first : p1.second < p2.second;
        };
        typedef priority_queue<pair<string, int>, vector<pair<string, int> >, decltype(comp) > my_pq;
        my_pq pq(comp);
        for (auto& s : cur->counts) {
            pq.emplace(s.first, s.second);
        }
        int i = 3;
        while (!pq.empty() && i > 0) {
            res.push_back(pq.top().first);
            pq.pop();
            i--;
        }
        return res;
    }
    TrieNode *root;
    string prefix_sentence;
};

void printVec(vector<string>& vec) {
    for (string& s : vec)
        cout << s << " ";
    cout << endl;
}

int main () {
    vector<string> sentences = {"i love you", "island", "iroman"};
    vector<int> times = {5,3,2,2};
    AutocompleteSystem obj(sentences, times);
    vector<string> param_1 = obj.input('i');
    printVec(param_1);
    vector<string> param_2 = obj.input(' ');
    printVec(param_2);
    vector<string> param_3 = obj.input('a');
    printVec(param_3);
    vector<string> param_4 = obj.input('#');
    printVec(param_4);
    return 0;
}
