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
    map <string, int> mp;

public:
    vector< vector <string> > groupAnagrams(vector <string>& strs) {
        vector <vector <string> > result;
        for (int i = 0; i < SZ(strs); ++ i) {
            string tmp(strs[i]);
            sort(tmp.begin(), tmp.end());
            if (mp[tmp] == 0) {
                mp[tmp] = SZ(result) + 1;
                vector <string> tmp_v;
                tmp_v.push_back(strs[i]);
                result.push_back(tmp_v);
            }
            else {
                result[mp[tmp] - 1].push_back(strs[i]);
            }
        }
        for (int i = 0; i < SZ(result); ++ i) {
            sort(result[i].begin(), result[i].end());
        }
        return result;
    }
};

int main() {
    string input[2] = {"c", "c"};
    vector <string> strs;
    for (int i = 0; i < 2; ++ i)
        strs.push_back(input[i]);
    Solution solution = Solution();
    vector < vector <string> > result = solution.groupAnagrams(strs);
    for (int i = 0; i < SZ(result); ++ i) {
        for (int j = 0; j < SZ(result[i]); ++ j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
