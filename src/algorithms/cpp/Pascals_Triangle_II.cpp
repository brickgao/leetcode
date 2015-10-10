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
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector <int> result {1};
        if (rowIndex == 0)   return result;
        if (rowIndex >= 1) {
            for (int i = 1; i <= rowIndex; ++ i) {
                int pre = 1;
                for (int j = 1; j < SZ(result); ++ j) {
                    int now = result[j];
                    result[j] = pre + now;
                    pre = now;
                }
                result.push_back(1);
            }
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    for (int i = 1; i < 5; ++ i) {
        vector <int> result = solution.getRow(i);
        for (int num: result) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
