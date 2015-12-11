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
    int hIndex(vector<int>& citations) {
        if (SZ(citations) == 0)        return 0;
        int l = 1, r = SZ(citations);
        while (l < r - 1) {
            int mid = (l + r) >> 1;
            int le_num = SZ(citations) - mid;
            if (citations[le_num - 1] > mid)   l = mid;
            else                               r = mid;
        }
        int le_num = SZ(citations) - r;
        if ((le_num == 0 || (le_num >= 1 && citations[le_num - 1] <= r)) && citations[le_num] >= r)       return r;
        le_num = SZ(citations) - l;
        if ((le_num == 0 || (le_num >= 1 && citations[le_num - 1] <= l)) && citations[le_num] >= l)       return l;
        return 0;
    }
};


int main() {
    return 0;
}
