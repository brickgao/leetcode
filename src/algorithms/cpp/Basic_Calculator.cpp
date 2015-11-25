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
private:
    string eval(vector <string> &v) {
        if (SZ(v) == 1)     return v[0];
        int ret = atoi(v[0].c_str());
        for (int i = 2; i < SZ(v); i += 2) {
            if (v[i - 1] == "-")    ret -= atoi(v[i].c_str());
            else                    ret += atoi(v[i].c_str());
        }
        return to_string(ret);
    }

public:
    int calculate(string s) {
        stack <string> st;
        int i = 0;
        s = '(' + s + ')';
        while (i < SZ(s)) {
            if (s[i] != ')') {
                if (s[i] == '+' || s[i] == '-' || s[i] == '(') {
                    st.push(string(1, s[i]));
                    ++ i;
                }
                else if (s[i] == ' ') {
                    ++ i;
                }
                else {
                    string s_tmp;
                    while (i < SZ(s) && s[i] >= '0' && s[i] <= '9') {
                        s_tmp += s[i];
                        ++ i;
                    }
                    st.push(s_tmp);
                }
            }
            else {
                vector <string> v;
                while (!st.empty()) {
                    string s_tmp = st.top();
                    st.pop();
                    if (s_tmp == "(")   break;
                    v.push_back(s_tmp);
                }
                reverse(v.begin(), v.end());
                st.push(eval(v));
                ++ i;
            }
        }
        return atoi(st.top().c_str());
    }
};

int main() {
    Solution solution;
    cout << solution.calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    cout << solution.calculate("1 + 1") << endl;
    return 0;
}
