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
    string alphas = "abcdefghijklmnopqrstuvwxyz", digits = "";
    map <char, pair <int, int> > mp;
    vector <string> results;

private:
    void init() {
        mp['2'] = make_pair(0, 3), mp['3'] = make_pair(3, 6);
        mp['4'] = make_pair(6, 9), mp['5'] = make_pair(9, 12);
        mp['6'] = make_pair(12, 15), mp['7'] = make_pair(15, 19);
        mp['8'] = make_pair(19, 22), mp['9'] = make_pair(22, 26);
    }

private:
    void dfs(int now, string now_s) {
        if (now == SZ(digits)) {
            results.push_back(now_s);
            return;
        }
        char number_now = digits[now];
        for (int i = mp[number_now].first; i < mp[number_now].second; ++ i) {
            string tmp = now_s + alphas[i];
            dfs(now + 1, tmp);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits == "")   return results;
        init();
        this->digits = digits;
        dfs(0, "");
        return results;
    }
};

int main() {
    Solution solution = Solution();
    vector <string> results = solution.letterCombinations("23");
    cout << SZ(results) << endl;
    for (auto s: results) {
        cout << s << endl;
    }
    return 0;
}
