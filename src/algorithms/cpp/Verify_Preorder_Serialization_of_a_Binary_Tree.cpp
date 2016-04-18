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
const double eps = 1e-6;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}


class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder == "")     return false;
        int index = 0;
        stack <int> st;
        string tmp;
        preorder += ",";
        st.push(0);
        while (index < SZ(preorder)) {
            if (preorder[index] == ',') {
                st.top() += 1;
                while (!st.empty() && st.top() == 2)  st.pop();
                if (st.empty())     return false;
                if (tmp != "#")     st.push(0);
                tmp = "";
            }
            else {
                tmp += preorder[index];
            }
            ++ index;
        }
        return SZ(st) == 1 && st.top() == 1 ? true : false;
    }
};


int main() {
    Solution solution = Solution();
    cout << solution.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
    cout << solution.isValidSerialization("1,#") << endl;
    cout << solution.isValidSerialization("9,#,#,1") << endl;
    return 0;
}
