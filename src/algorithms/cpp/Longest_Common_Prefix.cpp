#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if (strs.empty())  return "";
        while (true) {
            bool tag = true;
            for (int i = 0; i < SZ(strs); ++ i) {
                if (SZ(prefix) >= SZ(strs[i]) || strs[i][SZ(prefix)] != strs[0][SZ(prefix)]) {
                    tag = false;
                    break;
                }
            }
            if (!tag)  return prefix;
            prefix += strs[0][SZ(prefix)];
        }
        return prefix;
    }
};


int main() {
    vector <string> v;
    v.push_back(""), v.push_back("");
    Solution solution = Solution();
    cout << solution.longestCommonPrefix(v) << endl;
    return 0;
}
