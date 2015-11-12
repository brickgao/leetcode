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
    bool isHappy(int n) {
        int tmp = n;
        set <int> vis;
        while (tmp != 1 && vis.count(tmp) == 0) {
            int nxt_tmp = 0;
            string s_tmp = to_string(tmp);
            vis.insert(tmp);
            for (char &ch: s_tmp)
                nxt_tmp += (ch - '0') * (ch - '0');
            tmp = nxt_tmp;
        }
        return tmp == 1;
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.isHappy(19) << endl;
    return 0;
}
