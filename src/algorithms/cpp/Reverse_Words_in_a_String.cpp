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
    void reverseWords(string &s) {
        vector <string> rec;
        string tmp_s = "", ret = "";
        s += ' ';
        for (int i = 0; i < SZ(s); ++ i) {
            if (s[i] == ' ') {
                if (tmp_s != "")    rec.push_back(tmp_s), tmp_s = "";
            }
            else {
                tmp_s += s[i];
            }
        }
        for (auto it = rec.crbegin(); it != rec.crend(); ++ it) {
            if (it != rec.crbegin())    ret += ' ';
            ret += *it;
        }
        s = ret;
    }
};

int main() {
    Solution solution = Solution();
    string input_s = "the sky is blue";
    solution.reverseWords(input_s);
    cout << input_s << endl;
    return 0;
}
