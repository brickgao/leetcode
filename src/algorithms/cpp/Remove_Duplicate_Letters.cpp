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
    string removeDuplicateLetters(string s) {
        stack <int> st;
        map <int, int> mp;
        set <char> vis;
        for (char ch: s)
            mp[ch] += 1;
        for (char ch: s) {
            if (vis.count(ch) == 0) {
                while (!st.empty() && st.top() > ch && mp[st.top()] > 0) {
                    vis.erase(st.top());
                    st.pop();
                }
                st.push(ch);
                vis.insert(ch);
            }
            mp[ch] --;
        }
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    return 0;

