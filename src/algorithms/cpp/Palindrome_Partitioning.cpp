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
private:
    map <string, int> is_pa;

    inline bool is_palindrome(string &s1) {
        if (is_pa[s1] != 0) {
            if (is_pa[s1] == -1)    return false;
            else                    return true;
        }
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        if (s1 == s2) {
            is_pa[s1] = 1;
            return true;
        }
        else {
            is_pa[s1] = -1;
            return false;
        }
    }

public:
    vector <vector <string> > partition(string s) {
        vector <vector <vector <string> >> dp;
        dp.push_back(vector <vector <string> > {{}});
        for (int i = 0; i < SZ(s); ++ i) {
            vector <vector <string> > tmp_v;
            for (int j = 0; j <= i; ++ j) {
                string tmp_s = string(s.begin() + j, s.begin() + i + 1);
                if (is_palindrome(tmp_s)) {
                    for (auto last: dp[j]) {
                        last.push_back(tmp_s);
                        tmp_v.push_back(last);
                    }
                }
            }
            dp.push_back(tmp_v);
        }
        return dp[SZ(dp) - 1];
    }
};

int main() {
    Solution solution = Solution();
    vector <vector <string> > result = solution.partition("aab");
    for (auto v: result) {
        for (auto s: v)
            cout << s << " ";
        cout << endl;
    }
    return 0;
}
