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
    int compareVersion(string version1, string version2) {
        vector <int> v1, v2;
        int tmp = 0;
        for (int i = 0; i < SZ(version1); ++ i) {
            if (version1[i] == '.') {
                v1.push_back(tmp);
                tmp = 0;
                continue;
            }
            tmp *= 10;
            tmp += version1[i] - '0';
        }
        v1.push_back(tmp);
        tmp = 0;
        for (int i = 0; i < SZ(version2); ++ i) {
            if (version2[i] == '.') {
                v2.push_back(tmp);
                tmp = 0;
                continue;
            }
            tmp *= 10;
            tmp += version2[i] - '0';
        }
        v2.push_back(tmp);
        int min_len = min(SZ(v1), SZ(v2));
        for (int i = 0; i < min_len; ++ i) {
            if (v1[i] > v2[i])  return 1;
            if (v1[i] < v2[i])  return -1;
        }
        if (SZ(v1) == SZ(v2))   return 0;
        else if (SZ(v1) > SZ(v2)) {
            for (int i = min_len; i < SZ(v1); ++ i)
                if (v1[i] != 0) return 1;
            return 0;
        }
        else {
            for (int i = min_len; i < SZ(v2); ++ i)
                if (v2[i] != 0) return -1;
            return 0;
        }
    }
};

int main() {
    string version1 = "1", version2 = "1.1";
    Solution solution = Solution();
    cout << solution.compareVersion(version1, version2) << endl;
    return 0;
}
