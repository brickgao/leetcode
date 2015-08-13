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
    bool isValid(string s) {
        stack <char> st;
        for (int i = 0; i < SZ(s); ++ i) {
            char ch = s[i];
            if (!st.empty() && ch == ')' && st.top() == '(')    st.pop();
            else if (!st.empty() && ch == ']' && st.top() == '[')   st.pop();
            else if (!st.empty() && ch == '}' && st.top() == '{')   st.pop();
            else    st.push(ch);
        }
        return st.empty();
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.isValid("()[]{}") << endl;
    return 0;
}
