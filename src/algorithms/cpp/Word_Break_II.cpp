#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector <string> dp[300];
        bool dp_bool[300];
        int max_word_len = 0;
        for (auto word: wordDict)   get_max(max_word_len, SZ(word));
        for (int i = 0; i <= SZ(s); ++ i)   dp[i].clear(), dp_bool[i] = false;
        dp_bool[0] = true;
        for (int i = 0; i < SZ(s); ++ i) {
            string tmp_s = "";
            if (dp_bool[i] == false)    continue;
            for (int j = 0; j < max_word_len; ++ j) {
                if (i + j >= SZ(s)) break;
                tmp_s += s[i + j];
                if (wordDict.count(tmp_s) != 0) dp_bool[i + j + 1] = true;
            }
        }
        if (dp_bool[SZ(s)] == false)    return vector <string> {};
        cout << "fuck" << endl;
        dp[0].push_back("");
        for (int i = 0; i < SZ(s); ++ i) {
            string tmp_s = "";
            if (SZ(dp[i]) == 0)     continue;
            for (int j = 0; j < max_word_len; ++ j) {
                if (i + j >= SZ(s)) break;
                tmp_s += s[i + j];
                if (wordDict.count(tmp_s) != 0) {
                    for (auto &s: dp[i]) {
                        if (i == 0)     dp[i + j + 1].push_back(s + tmp_s);
                        else            dp[i + j + 1].push_back(s + " " + tmp_s);
                    }
                }
            }
        }
        return dp[SZ(s)];
    }
};

int main() {
    Solution solution = Solution();
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    unordered_set <string> d = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    vector <string> result = solution.wordBreak(s, d);
    for (auto s: result)
        cout << s << endl;
    return 0;
}
