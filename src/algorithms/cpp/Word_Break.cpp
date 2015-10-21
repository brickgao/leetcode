#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}


bool dp[10000];

class Solution {
public:
    bool wordBreak(string s, unordered_set <string> &wordDict) {
        int max_word_len = 0;
        dp[0] = true;
        for (auto word: wordDict)   get_max(max_word_len, SZ(word));
        for (int i = 1; i <= SZ(s); ++ i)   dp[i] = false;
        for (int i = 1; i <= SZ(s); ++ i) {
            string tmp_s = "";
            if (dp[i - 1] == false)   continue;
            for (int j = 0; j < max_word_len; ++ j) {
                tmp_s += s[i + j - 1];
                if (wordDict.count(tmp_s) != 0)
                    dp[i + j] = true;
            }
        }
        return dp[SZ(s)];
    }
};

int main() {
    string s = "a";
    unordered_set <string> d = {"b"};
    Solution solution = Solution();
    cout << solution.wordBreak(s, d) << endl;
    return 0;
}
