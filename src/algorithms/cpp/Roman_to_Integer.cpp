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
    int romanToInt(string s) {
        map <char, int> mp;
        mp['M'] = 1000, mp['D'] = 500;
        mp['C'] = 100, mp['L'] = 50;
        mp['X'] = 10, mp['V'] = 5;
        mp['I'] = 1;
        int pos = 0, result = 0;
        while (pos + 1 < SZ(s)) {
            if (mp[s[pos]] >= mp[s[pos + 1]]) {
                result += mp[s[pos]];
                pos += 1;
            }
            else {
                result += mp[s[pos + 1]] - mp[s[pos]];
                pos += 2;
            }
        }
        if (pos != SZ(s))   result += mp[s[pos]];
        return result;
    }
};


int main() {
    Solution solution = Solution();
    cout << solution.romanToInt("II") << endl;
    cout << solution.romanToInt("IV") << endl;
    return 0;
}
