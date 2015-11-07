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
    vector<string> findRepeatedDnaSequences(string s) {
        map <string, int> mp;
        for (int i = 0; i < SZ(s) - 9; ++ i) {
            string tmp_s = string(s.begin() + i, s.begin() + i + 10);
            ++ mp[tmp_s];
        }
        vector <string> result;
        for (auto it = mp.cbegin(); it != mp.cend(); ++ it) {
            if (it->second > 1)     result.push_back(it->first);
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    vector <string> result = solution.findRepeatedDnaSequences("AAAAAAAAAAA");
    for (auto s: result) {
        cout << s << endl;
    }
    return 0;
}
