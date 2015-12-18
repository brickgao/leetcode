#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
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
    set <string> vis;
    vector <string> result;

public:
    vector<string> removeInvalidParentheses(string s) {
        int remove_len = this->getRemoveLen(s);
        if (remove_len == 0) {
            return vector <string> {s};
        }
        else {
            vis.insert(s);
            this->dfs(s, remove_len);
            return this->result;
        }
    }

private:
    int getRemoveLen(string &s) {
        stack <char> st;
        for (auto &c: s) {
            if (c == '(' || c == ')') {
                if (!st.empty() && st.top() == '(' && c == ')')     st.pop();
                else                                                st.push(c);
            }
        }
        return SZ(st);
    }

    void dfs(string s, int left) {
        for (int i = 0; i < SZ(s); ++ i) {
            string new_s = string(s.begin(), s.begin() + i) + string(s.begin() + i + 1, s.end());
            if (vis.count(new_s) == 0 && this->getRemoveLen(new_s) < left) {
                vis.insert(new_s);
                if (left <= 1) {
                    this->result.push_back(new_s);
                }
                else {
                    this->dfs(new_s, left - 1);
                }
            }
        }
    }
};

int main() {
    return 0;
}
