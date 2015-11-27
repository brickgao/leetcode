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
    int get_mul_and_div_val(vector <string> &v) {
        int ret = atoi(v[0].c_str());
        for (int i = 2; i < SZ(v); i += 2) {
            if (v[i - 1] == "*")    ret *= atoi(v[i].c_str());
            else                    ret /= atoi(v[i].c_str());
        }
        return ret;
    }

    int get_add_and_sub_val(vector <string> &v) {
        int ret = atoi(v[0].c_str());
        for (int i = 2; i < SZ(v); i += 2) {
            if (v[i - 1] == "+")    ret += atoi(v[i].c_str());
            else                    ret -= atoi(v[i].c_str());
        }
        return ret;
    }

public:
    int calculate(string s) {
        int i = 0;
        vector <string> v, tmp_v;
        while (i < SZ(s)) {
            if (s[i] == ' ') {
                ++ i;
            }
            else if (s[i] == '+' || s[i] == '-') {
                v.push_back(to_string(get_mul_and_div_val(tmp_v)));
                tmp_v.clear();
                v.push_back(string(1, s[i]));
                ++ i;
            }
            else if (s[i] == '*' || s[i] == '/') {
                tmp_v.push_back(string(1, s[i]));
                ++ i;
            }
            else {
                string s_tmp = "";
                while (i < SZ(s) && s[i] >= '0' && s[i] <= '9')
                    s_tmp += s[i ++];
                tmp_v.push_back(s_tmp);
            }
        }
        if (SZ(tmp_v) != 0) {
            v.push_back(to_string(get_mul_and_div_val(tmp_v)));
            tmp_v.clear();
        }
        return get_add_and_sub_val(v);
    }
};


int main() {
    Solution solution;
    cout << solution.calculate("3+2*2") << endl;
    return 0;
}
