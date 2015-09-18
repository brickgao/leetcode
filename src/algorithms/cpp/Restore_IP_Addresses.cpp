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
    string s;
    vector <string> tmp_v;
    vector <string> result;

private:
    inline bool isvalid(string s) {
        int tmp = 0;
        if (s[0] == '0' && SZ(s) > 1)
            return false;
        for (int i = 0; i < SZ(s); ++ i) {
            tmp *= 10;
            tmp += s[i] - '0';
        }
        return tmp <= 255;
    }

private:
    void dfs(int now) {
        if (SZ(tmp_v) == 4) {
            if (now >= SZ(s)) {
                string s_tmp = "";
                for (int i = 0; i < SZ(tmp_v); ++ i) {
                    if (i)  s_tmp += ".";
                    s_tmp += tmp_v[i];
                }
                result.push_back(s_tmp);
            }
            return;
        }
        int upper = min(now + 3, SZ(s));
        for (int i = now + 1; i <= upper; ++ i) {
            string s_tmp = string (s.begin() + now, s.begin() + i);
            if (isvalid(s_tmp)) {
                tmp_v.push_back(s_tmp);
                dfs(i);
                tmp_v.pop_back();
            }
        }
    }

public:
    vector <string> restoreIpAddresses(string s) {
        this->s = s;
        dfs(0);
        return result;
    }
};

int main() {
    Solution solution = Solution();
    vector <string> result = solution.restoreIpAddresses("25525511135");
    for (auto s: result) {
        cout << s << endl;
    }
    return 0;
}
