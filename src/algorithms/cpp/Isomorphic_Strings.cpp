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
    bool isIsomorphic(string s, string t) {
        map <char, char> mp1, mp2;
        for (int i = 0; i < static_cast <int> (s.size()); ++ i) {
            if (mp1.count(s[i]) > 0 && mp2.count(t[i]) > 0) {
                if (mp1[s[i]] != t[i] || mp2[t[i]] != s[i])     return false;
            }
            else {
                if (mp1.count(s[i]) == 0 && mp2.count(t[i]) == 0) {
                    mp1[s[i]] = t[i], mp2[t[i]] = s[i];
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    return 0;
}
