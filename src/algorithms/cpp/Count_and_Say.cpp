#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stack>
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
    string countAndSay(int n) {
        string now = "1";
        for (int i = 1; i < n; ++ i) {
            string tmp = "";
            char pre = '-';
            int cnt = 0;
            for (int i = 0; i < SZ(now); ++ i) {
                if (now[i] != pre) {
                    if (pre != '-') {
                        char tmp_c_str[50];
                        sprintf(tmp_c_str, "%d", cnt);
                        tmp += string (tmp_c_str) + pre;
                    }
                    pre = now[i];
                    cnt = 1;
                }
                else {
                    cnt += 1;
                }
            }
            char tmp_c_str[50];
            sprintf(tmp_c_str, "%d", cnt);
            tmp += string (tmp_c_str) + pre;
            now = tmp;
        }
        return now;
    }
};

int main() {
    return 0;
}
