#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}


class Solution {
public:
    vector <vector <int>> palindromePairs(vector<string>& words) {
        map <string, int> mp;
        vector <vector <int>> result;
        for (int i = 0; i < SZ(words); ++ i) {
            string tmp = words[i];
            reverse(tmp.begin(), tmp.end());
            mp[tmp] = i;
        }
        if (mp.find("") != mp.end()) {
            for (int i = 0; i < SZ(words); ++ i)
                if (is_palindrome(words[i]) && words[i] != "")
                    result.push_back({mp[""], i});
        }
        for (int i = 0; i < SZ(words); ++ i) {
            for (int j = 0; j < SZ(words[i]); ++ j) {
                string part1 = words[i].substr(0, j);
                string part2 = words[i].substr(j, SZ(words[i]) - j);
                if (mp.find(part1) != mp.end() && is_palindrome(part2) && mp[part1] != i)
                    result.push_back({i, mp[part1]});
                if (mp.find(part2) != mp.end() && is_palindrome(part1) && mp[part2] != i)
                    result.push_back({mp[part2], i});
            }
        }
        return result;
    }

private:
    bool is_palindrome(string &str) {
        bool ret = true;
        for (int i = 0; i < SZ(str) / 2; ++ i) {
            if (str[i] != str[SZ(str) - i - 1]) {
                ret = false;
            }
        }
        return ret;
    }
};


int main() {
    return 0;
}
