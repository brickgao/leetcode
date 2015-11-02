#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
typedef long long LL;
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
public:
    string convertToTitle(int n) {
        map <int, char> mp;
        for (int i = 0; i < 26; ++ i)
            mp[i] = 'A' + i;
        string result = "";
        int left = n;
        while (left > 0) {
            left -= 1;
            result = mp[left % 26] + result;
            left /= 26;
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.convertToTitle(1) << endl;
    cout << solution.convertToTitle(2) << endl;
    cout << solution.convertToTitle(26) << endl;
    cout << solution.convertToTitle(27) << endl;
    cout << solution.convertToTitle(28) << endl;
    cout << solution.convertToTitle(29) << endl;
    return 0;
}
