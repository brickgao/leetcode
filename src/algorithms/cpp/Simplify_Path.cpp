#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
public:
    string simplifyPath(string path) {
        int now = 0;
        stack <string> st;
        string tmp_s = "";
        while (now < SZ(path)) {
            if (path[now] == '/') {
                if (tmp_s != "" && tmp_s != ".") {
                    if (tmp_s == "..") {
                        if (!st.empty())
                            st.pop();
                    }
                    else                st.push(tmp_s);
                }
                tmp_s = "";
            }
            else {
                tmp_s += path[now];
            }
            ++ now;
        }
        if (tmp_s != "" && tmp_s != ".") {
            if (tmp_s == "..") {
                if (!st.empty())
                    st.pop();
            }
            else                st.push(tmp_s);
        }
        string result = "";
        while (!st.empty()) {
            string tmp = st.top();
            result = "/" + tmp + result;
            st.pop();
        }
        if (result == "")
            result = "/";
        return result;
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.simplifyPath("/home/") << endl;
    cout << solution.simplifyPath("/a/./b/../../c/") << endl;
    cout << solution.simplifyPath("/..") << endl;
    return 0;
}
