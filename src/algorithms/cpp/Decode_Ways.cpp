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
    int numDecodings(string s) {
        set <string> number_set;
        int dp[100000] = {};
        if (s == "")    return 0;
        for (int i = 1; i <= 26; ++ i) {
            string s_tmp = "";
            if (i >= 10) {
                s_tmp += char('0' + i / 10);
                s_tmp += char('0' + i % 10);
            }
            else {
                s_tmp += char('0' + i);
            }
            number_set.insert(s_tmp);
        }
        dp[0] = 1;
        for (int i = 0; i < SZ(s); ++ i) {
            if (i >= 1 && number_set.count(string (s.begin() + i - 1, s.begin() + i + 1)) != 0)
                dp[i + 1] += dp[i - 1];
            if (number_set.count(string (s.begin() + i, s.begin() + i + 1)) != 0)
                dp[i + 1] += dp[i];
        }
        return dp[SZ(s)];
    }
};

int main() {
    string s = "12";
    Solution solution = Solution();
    cout << solution.numDecodings(s) << endl;
    return 0;
}
