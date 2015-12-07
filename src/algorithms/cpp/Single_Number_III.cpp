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
    vector<int> singleNumber(vector<int>& nums) {
        int xor_result = 0;
        for (int &num: nums)    xor_result ^= num;
        int cnt = 0;
        while (xor_result) {
            if (xor_result & 1)
                break;
            ++ cnt;
            xor_result >>= 1;
        }
        int diff = (1 << cnt);
        int a = 0, b = 0;
        for (int &num: nums) {
            if (diff & num)
                a ^= num;
            else
                b ^= num;
        }
        return vector <int> {a, b};
    }
};

int main() {
    Solution solution;
    vector <int> input = {1, 2, 1, 3, 2, 5};
    vector <int> result = solution.singleNumber(input);
    for (int &num: result) {
        cout << num << endl;
    }
    return 0;
}
