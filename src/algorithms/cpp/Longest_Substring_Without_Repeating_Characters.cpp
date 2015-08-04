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
    int lengthOfLongestSubstring(string s) {
        int mp[300], result = 0, len = 0;
        memset(mp, -1, sizeof(mp));
        for (int i = 0; i < SZ(s); ++ i) {
            if (mp[s[i]] != -1) {
                if (i - mp[s[i]] <= len) {
                    len = i - mp[s[i]];
                }
                else {
                    len += 1;
                }
            }
            else {
                len += 1;
            }
            get_max(result, len);
            mp[s[i]] = i;
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.lengthOfLongestSubstring("aa") << endl;
    cout << solution.lengthOfLongestSubstring("aab") << endl;
    cout << solution.lengthOfLongestSubstring("abba") << endl;
    return 0;
}
