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

class NumArray {
private:
    vector <int> sums;
    int n;

public:
    NumArray(vector<int> &nums) {
        int len = (SZ(nums) << 2) + 1;
        for (int i = 0; i < len; ++ i)
            sums.push_back(0);
        this->n = SZ(nums);
        for (int i = 0; i < SZ(nums); ++ i) {
            this->SGUpdate(i + 1, nums[i], 1, this->n, 1);
        }
    }
    
    void SGPushUp(int rt) {
        this->sums[rt] = this->sums[rt << 1] + this->sums[rt << 1 | 1];
    }
    
    void SGUpdate(int pos, int c, int l, int r, int rt) {
        if (l == r && l == pos) {
            this->sums[rt] = c;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            this->SGUpdate(pos, c, l, mid, rt << 1);
        else
            this->SGUpdate(pos, c, mid + 1, r, rt << 1 | 1);
        this->SGPushUp(rt);
    }
    
    int SGQuery(int L, int R, int l, int r, int rt) {
        if (L <= l && r <= R) {
            return this->sums[rt];
        }
        int mid = (l + r) >> 1, ret = 0;
        if (L <= mid)
            ret += this->SGQuery(L, R, l, mid, rt << 1);
        if (mid < R)
            ret += this->SGQuery(L, R, mid + 1, r, rt << 1 | 1);
        return ret;
    }

    void update(int i, int val) {
        this->SGUpdate(i + 1, val, 1, this->n, 1);
    }

    int sumRange(int i, int j) {
        return this->SGQuery(i + 1, j + 1, 1, this->n, 1);
    }
};


int main() {
    return 0;
}
