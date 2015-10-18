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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector <int> rec;
        for (int i = 0; i < SZ(gas); ++ i)
            rec.push_back(gas[i] - cost[i]);
        int tmp = 0, ret = 0;
        for (int i = 0; i < SZ(gas); ++ i) {
            tmp += rec[i];
            if (tmp < 0) {
                ret = (i + 1) % SZ(gas);
                tmp = 0;
            }
        }
        tmp = 0;
        for (int i = 0; i < SZ(gas); ++ i) {
            tmp += rec[(i + ret) % SZ(gas)];
            if (tmp < 0)    return -1;
        }
        return ret;
    }
};

int main() {
    Solution solution = Solution();
    vector <int> input1 = {2, 3, 1}, input2 = {3, 1, 2};
    cout << solution.canCompleteCircuit(input1, input2) << endl;
    return 0;
}
