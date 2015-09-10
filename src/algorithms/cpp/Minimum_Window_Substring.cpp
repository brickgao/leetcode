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
    string minWindow(string s, string t) {
        bool vis[256] = {};
        map <char, int> s_rec, t_rec;
        int l_pos = 0, cnt = 0;
        int ret_l = -1, ret_r = -1, minn = SZ(s) + 1;
        for (int i = 0; i < SZ(t); ++ i)
            ++ t_rec[t[i]];
        for (int i = 0; i < SZ(s); ++ i) {
            ++ s_rec[s[i]];
            bool tag1 = false;
            if (s_rec[s[i]] >= t_rec[s[i]]) {
                if (!vis[int(s[i])])
                    vis[int(s[i])] = true, ++ cnt;
                if (cnt >= SZ(t_rec))
                    tag1 = true;
            }
            if (tag1) {
                while (l_pos <= i) {
                    if (s_rec[s[l_pos]] > t_rec[s[l_pos]]) 
                        -- s_rec[s[l_pos]], ++ l_pos;
                    else 
                        break;
                }
                if (i - l_pos + 1 < minn) {
                    ret_l = l_pos, ret_r = i + 1;
                    minn = i - l_pos + 1;
                }
            }
        }
        if (ret_l == -1)    return "";
        else                return string (s.begin() + ret_l, s.begin() + ret_r);
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << solution.minWindow("a", "a") << endl;
    return 0;
}
