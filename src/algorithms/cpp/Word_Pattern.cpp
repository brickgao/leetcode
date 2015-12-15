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
    bool wordPattern(string pattern, string str) {
        map <char, string> mp;
        map <string, char> reverse_mp;
        vector <string> strs;
        string tmp;
        str += ' ';
        for (int i = 0; i < SZ(str); ++ i) {
            if (str[i] == ' ') {
                if (tmp != "")  strs.push_back(tmp);
                tmp = "";
            }
            else {
                tmp += str[i];
            }
        }
        if (SZ(pattern) != SZ(strs))    return false;
        for (int i = 0; i < SZ(pattern); ++ i) {
            if (mp.count(pattern[i]) > 0 || reverse_mp.count(strs[i]) > 0) {
                if (mp[pattern[i]] != strs[i])              return false;
                if (reverse_mp[strs[i]] != pattern[i])      return false;
            }
            else {
                mp[pattern[i]] = strs[i];
                reverse_mp[strs[i]] = pattern[i];
            }
        }
        return true;
    }
};

int main() {
    return 0;
}
