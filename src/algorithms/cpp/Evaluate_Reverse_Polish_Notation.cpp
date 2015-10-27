#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        int i = 0;
        while (i < SZ(tokens)) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                if (tokens[i] == "+")   st.push(num1 + num2);
                if (tokens[i] == "-")   st.push(num1 - num2);
                if (tokens[i] == "*")   st.push(num1 * num2);
                if (tokens[i] == "/")   st.push(num1 / num2);
            }
            else {
                int now = 0, beg = 0, tag = 1;
                if (tokens[i][0] == '-')    beg = 1, tag = -1;
                for (int j = beg; j < SZ(tokens[i]); ++ j) {
                    now *= 10;
                    now += tokens[i][j] - '0';
                }
                st.push(now * tag);
            }
            ++ i;
        }
        return st.top();
    }
};

int main() {
    vector <string> token1 = {"2", "1", "+", "3", "*"};
    vector <string> token2 = {"4", "13", "5", "/", "+"};
    Solution solution = Solution();
    cout << solution.evalRPN(token1) << endl;
    cout << solution.evalRPN(token2) << endl;
    return 0;
}
