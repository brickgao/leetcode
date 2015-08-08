#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
private:
    bool chMatch(char ch, pair <char, char> p) {
        if (p.first == '.')
            return true;
        if (p.first == ch)
            return true;
        else 
            return false;
    }

public:
    bool isMatch(string s, string p) {
        int pos = 0;
        vector <pair <char, char> > v;
        if (s == "" && p == "") return true;
        if (s != "" && p == "") return false;
        while (pos + 1 < SZ(p)) {
            if (p[pos + 1] == '*') {
                v.push_back(pair <char, char> (p[pos], '*'));
                pos += 2;
            }
            else {
                v.push_back(pair <char, char> (p[pos], ' '));
                pos += 1;
            }
        }
        if (pos < SZ(p)) {
            v.push_back(pair <char, char> (p[pos], ' '));
        }
        if (s == "") {
            bool tag = true;
            for (int i = 0; i < SZ(v); ++ i)
                if (v[i].second != '*') {
                    tag = false;
                    break;
                }
            return tag;
        }
        bool dp[1000][1000] = {};
        dp[SZ(s)][SZ(v)] = true;
        for (int i = SZ(s); i >= 0; i -= 1) {
            for (int j = SZ(v) - 1; j >= 0; j -= 1) {
                if (i < SZ(s) && dp[i + 1][j + 1] && chMatch(s[i], v[j]))
                    dp[i][j] = true;
                if (i < SZ(s) && dp[i + 1][j] && v[j].second == '*' && chMatch(s[i], v[j]))
                    dp[i][j] = true;
                if (dp[i][j + 1] && v[j].second == '*')
                    dp[i][j] = true;
            }
        }
        return dp[0][0];
    }
};


int main() {
    Solution solution = Solution();
    cout << solution.isMatch("aa", "a") << endl;
    cout << solution.isMatch("aa", "aa") << endl;
    cout << solution.isMatch("aaa", "aa") << endl;
    cout << solution.isMatch("aa", "a*") << endl;
    cout << solution.isMatch("aa", ".*") << endl;
    cout << solution.isMatch("ab", ".*") << endl;
    cout << solution.isMatch("aab", "c*a*b*") << endl;
    cout << solution.isMatch("", "c*a*b*") << endl;
    cout << solution.isMatch("a", "ab*") << endl;
    return 0;
}
