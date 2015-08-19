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
    int longestValidParentheses(string s) {
        stack <pair <char, int> > st;
        int result = 0;
        for (int i = 0; i < SZ(s); ++ i) {
            char ch = s[i];
            if (ch == '(') {
                st.push(make_pair(ch, i));
            }
            else {
                if (!st.empty() && st.top().first == '(') {
                    st.pop();
                    if (st.empty())
                        get_max(result, i + 1);
                    else
                        get_max(result, i - st.top().second);
                }
                else {
                    st.push(make_pair(ch, i));
                }
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
