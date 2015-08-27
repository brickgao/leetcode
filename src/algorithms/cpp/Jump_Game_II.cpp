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
    int jump(vector<int>& nums) {
        int upper_bound = 0, rec_bound = 0, cnt = 0;
        for (int i = 0; i < SZ(nums) - 1; ++ i) {
            get_max(upper_bound, i + nums[i]);
            if (i == rec_bound) {
                rec_bound = upper_bound;
                cnt += 1;
            }
        }
        return cnt;
    }
};

int main() {
    return 0;
}
