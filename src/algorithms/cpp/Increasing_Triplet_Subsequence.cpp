#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
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
    bool increasingTriplet(vector<int>& nums) {
        int minn = INT_MAX, mid = INT_MAX;
        for (int &num: nums) {
            if (num < minn) {
                minn = num;
            }
            else if (num > minn) {
                if (mid < num)    return true;
                mid = num;
            }
        }
        return false;
    }
};


int main() {
    return 0;
}
