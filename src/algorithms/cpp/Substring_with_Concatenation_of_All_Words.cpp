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
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector <int> result;
        map <string, int> mp;
        if (SZ(words) == 0)     return result;
        int len = SZ(words[0]);
        for (int i = 0; i < SZ(words); ++ i) {
            ++ mp[words[i]];
        }
        for (int i = 0; i < SZ(s) - len * SZ(words) + 1; ++ i) {
            map <string, int> tmp_mp(mp.begin(), mp.end());
            bool tag = true;
            for (int j = 0; j < SZ(words); ++ j) {
                string tmp_s = s.substr(i + j * len, len);
                tmp_mp[tmp_s] -= 1;
                if (tmp_mp[tmp_s] == -1) {
                    tag = false;
                    break;
                }
            }
            if (tag) {
                result.push_back(i);
            }
        }
        return result;
    }
};

int main() {
    vector <string> input_v;
    input_v.push_back("foo"), input_v.push_back("bar");
    Solution solution = Solution();
    vector <int> result = solution.findSubstring("barfoothefoobarman", input_v);
    for (auto i: result) {
        cout << i << endl;
    }
    return 0;
}
