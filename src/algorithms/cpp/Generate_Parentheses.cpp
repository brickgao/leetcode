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
    vector<string> generateParenthesis(int n) {
        vector < vector <string> > result;
        vector <string> tmp1, tmp2;
        tmp1.push_back(""), result.push_back(tmp1);
        tmp2.push_back("()"), result.push_back(tmp2);
        for (int i = 2; i <= n; ++ i) {
            vector <string> tmp3;
            for (int l = 0; l < i; ++ l) {
                int r = i - 1 - l;
                for (int i1 = 0; i1 < SZ(result[l]); ++ i1)
                    for (int i2 = 0; i2 < SZ(result[r]); ++ i2)
                        tmp3.push_back("(" + result[l][i1] + ")" + result[r][i2]);
            }
            result.push_back(tmp3);
        }
        sort(result[n].begin(), result[n].end());
        return result[n];
    }
};

int main() {
    Solution solution = Solution();
    vector <string> result = solution.generateParenthesis(3);
    cout << SZ(result) << endl;
    for (auto s: result) {
        cout << s << endl;
    }
    return 0;
}
