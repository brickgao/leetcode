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
    int addDigits(int num) {
        string s_sum = to_string(num);
        while (SZ(s_sum) != 1) {
            int nxt_num = 0;
            for (auto &ch: s_sum)
                nxt_num += ch - '0';
            s_sum = to_string(nxt_num);
        }
        return s_sum[0] - '0';
    }
};

int main() {
    return 0;
}
